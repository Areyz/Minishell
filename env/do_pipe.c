/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:59:40 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/09 22:50:44 by mgolasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_command(char *cmd)
{
	int	i;

	if (!cmd)
		return (0);
	i = 0;
	while (cmd[i] == ' ' || cmd[i] == '\t')
		i++;
	return (cmd[i] != '\0');
}

void	error_exit(int code, char *message)
{
	errno = code;
	perror(message);
	exit(EXIT_FAILURE);
}

void do_pipe(int argc, char *argv[], char *envp[])
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc != 5)
		error_exit(EINVAL, "Usage: file 1 cmd1 cmd2 file2\n");
	if (is_valid_command(argv[3]) == 0)
		error_exit(EINVAL, "Empty command");
	if (is_valid_command(argv[2]) == 0)
		error_exit(EINVAL, "Empty command");
	if (pipe(pipe_fd) == -1)
		error_exit(EAGAIN, "pipe error");
	pid = fork();
	if (pid == -1)
		error_exit(EAGAIN, "fork error");
	if (pid == 0)
		input_process(argv[1], argv[2], pipe_fd, envp);
	else
	{
		wait(NULL);
		output_process(argv[4], argv[3], pipe_fd, envp);
	}
	return (0);
}
