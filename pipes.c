/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:54:51 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/09/02 19:31:13 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_pipes(t_global *global, int pipe_n)
{
	int	i;

	i = 0;
	while (i < pipe_n)
	{
		if (pipe(global->pipe_fd[i++]) < 0)
		{
			perror("minishell: pipe");
			return (1);
		}
	}
	return (0);
}
