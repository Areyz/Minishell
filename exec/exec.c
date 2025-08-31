/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:16:07 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/08/31 18:13:28 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipes(t_shell *shell, int pipe_n)
{
	int	i;

	i = 0;
	while (i < pipe_n)
	{
		close(shell->pipe_fd[i][0]);
		close(shell->pipe_fd[i][1]);
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
	envtemp = env_array_from_enviro(global); //done
	//envtemp muste be char**
	target = find_path(global, i);
	if (global->command[i].arg[0] != NULL)
		execve(target, global->command[i].arg, envtemp);
	perror("minishell: command not found\n");
	free(target);
	free_string_array(envtemp);
	free_all(global);
	ft_clear_env(global->env);
	exit(127);
}

void	launch_command(t_global *global)
{
	int	i;
	int	cmd_n;
	int	pipe_n;

	cmd_n = global->command_nbr;
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