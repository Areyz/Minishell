/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childpar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:52:49 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/09 22:50:46 by mgolasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_fileperm(char *file)
{
	if (access(file, F_OK) == 0 && access(file, R_OK) == -1)
		error_exit(EACCES, file);
}

void	handle_exec(char *cmd, t_enviro *enviro)
{
	char	**args;
	char	*cmd_path;
	char 	**env;

	args = ft_split(cmd, ' ');
	if (!args)
		error_exit(EINVAL, "Command error");
	cmd_path = find_command(args[0], env);
	if (!cmd_path && args[0])
	{
		write(STDERR_FILENO, args[0], ft_strlen(args[0]));
		write(STDERR_FILENO, ": command not found\n", 20);
		free_split(args);
		exit(127);
	}
	env = rebuild_env(enviro);
	execve(cmd_path, args, env);
	free(cmd_path);
	free_split(args);
	error_exit(EACCES, "Error - empty command");
	exit(126);
}

void	input_process(char *infile, char *cmd1, int *pipe_fd, t_enviro *enviro)
{
	int		infile_fd;

	close(pipe_fd[0]);
	error_fileperm(infile);
	infile_fd = open(infile, O_RDONLY);
	if (infile_fd == -1)
		error_exit(ENOENT, infile);
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	handle_exec(cmd1, enviro);
}

void	output_process(char *outfile, char *cmd2, int *pipe_fd, char **env)
{
	int		outfile_fd;

	close(pipe_fd[1]);
	outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
		error_exit(EACCES, outfile);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	close(pipe_fd[0]);
	handle_exec(cmd2, enviro);
}
