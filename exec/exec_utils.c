/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:16:00 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/08/31 18:13:28 by kjamrosz         ###   ########.fr       */
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

char	*find_path_sub(t_shell *shell, int i)
{
	char	*target;
	char	*folder;
	int		offset;

	folder = NULL;
	target = NULL;
	offset = 0;
	while (1)
	{
		folder = next_folder(shell, &offset);
		target = multicat((char *[]){folder, "/",
				shell->command[i].args[0], 0});
		if (folder[0] == 0 || (access(target, F_OK) == 0))
			break ;
		safefree(target);
		safefree(folder);
	}
	safefree(folder);
	return (target);
}

char	*find_path(t_shell *shell, int i)
{
	char	*target;
	char	*folder;

	folder = NULL;
	if (ft_strncmp(shell->command[i].args[0], "/", 1) == 0)
		target = ft_strdup(shell->command[i].args[0]);
	else if (ft_strncmp(shell->command[i].args[0], "./", 2) == 0)
	{
		folder = ft_calloc(1024, 1);
		getcwd(folder, 1024);
		target = multicat((char *[]){folder,
				&shell->command[i].args[0][1], NULL});
	}
	else
		target = find_path_sub(shell, i);
	safefree(folder);
	return (target);
}