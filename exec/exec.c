/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:16:07 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/09/01 21:58:35 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_pipes(t_global *global, int pipe_n)
{
	int	i;

	i = 0;
	while (i < pipe_n)
	{
		close(global->pipe_fd[i][0]);
		close(global->pipe_fd[i][1]);
		i++;
	}
}

void	child_process(t_global *global, int i, int pipe_n)
{
	char	**envtemp;
	char	*target;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	handle_redirections(global, i, pipe_n);
	close_pipes(global, pipe_n);
	if (global->command[i].arg[0] == NULL)
		exit(0);
	ft_builtins(global, i);
	envtemp = env_array_from_enviro(global);
	printf("PATH=%s",getenv("PATH"));	//DEL
	target = find_path(global, i);
	printf("\ntarget=%s", target);	//DEL
	if (global->command[i].arg[0] != NULL)
		execve(target, global->command[i].arg, envtemp);
	perror("minishell: command not found");
	free(target);
	free_string_array(envtemp);
	free_all(global);
	ft_clear_env(global->enviro);
	exit(127);
}

static void	wait_for_children(t_global *global)
{
	int	i;
	int	status;
	int	cmd_n;

	i = 0;
	cmd_n = global->comand_nbr;
	while (i < cmd_n)
	{
		waitpid(global->pidz[i], &status, 0);
		if (i == cmd_n - 1)
		{
			if (WIFEXITED(status))
				global->last_exit_code = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				global->last_exit_code = 128 + WTERMSIG(status);
		}
		i++;
	}
}

void	launch_command(t_global *global)
{
	int	i;
	int	cmd_n;
	int	pipe_n;

	cmd_n = global->comand_nbr;
	pipe_n = cmd_n - 1;
	signal(SIGINT, handle_sigint_heredoc);
	if (create_pipes(global, pipe_n))
		return ;
	i = 0;
	while (i < cmd_n)
	{
		global->pidz[i] = fork();
		if (global->pidz[i] < 0)
		{
			perror("minishell: fork");
			return ;
		}
		if (global->pidz[i] == 0)
			child_process(global, i, pipe_n);
		i++;
	}
	close_pipes(global, pipe_n);
	wait_for_children(global);
	signal(SIGINT, sigint_handler);
}