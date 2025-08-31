/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:16:00 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/08/31 16:47:39 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_redirections(t_global *global, int i, int pipe_n)
{
	if (pipe_n > 0)
	{
		if (i == 0)
			dup2(global->pipe_fd[i][1], STDOUT_FILENO);
		else if (i == global->command_nbr - 1)
			dup2(global->pipe_fd[i - 1][0], STDIN_FILENO);
		else
		{
			dup2(global->pipe_fd[i - 1][0], STDIN_FILENO);
			dup2(global->pipe_fd[i][1], STDOUT_FILENO);
		}
	}
	if (global->command[i].redir_count > 0)
		redir_control(global, i);
}