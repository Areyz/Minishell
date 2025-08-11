/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:59:40 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/11 17:23:33 by mgolasze         ###   ########.fr       */
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

void do_pipe(t_extortion extortion, t_global *global)
{
	int			pipe_fd[2];
	pid_t		pid;

	if (is_valid_command(extortion->extortion))
		error_exit(EINVAL, "Empty command");
	if (pipe(pipe_fd) == -1)
		error_exit(EAGAIN, "Pipe error");
	pid = fork();
	if (pid == -1)
		error_exit(EAGAIN, "Fork error");
	if (extortion->direction == 0 && pid == 0)
		default_process(extortion, pipe_fd, global)
	else if (extortion->direction == 1 && pid == 0)
		input_process(extortion, pipe_fd, global);
	else if (((extortion->direction == 2) || (extortion->direction == 2)) && pid == 0)
		output_process(argv[4], argv[3], pipe_fd, envp);
	else
	{
		waitpid(pid, &status, 0);
	}
}

void	pipe_exe(t_global global)
{
	int		i;
	int		l;
	t_token	token;

	i = token->pipe_counter + 1;
	l = 0;
	while (l < i)
	{
		do_pipe(extortion);
		extortion->next;
		l++;
	}
}


if (token.type == >)
	extortion->direction == 1;