/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_extortion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:25:25 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/11 17:24:25 by mgolasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	do_extortion(t_global global, t_token token)
{
	t_extortion	extor;

	extor->pipe_count = token->pipe_count;
	while	(token)
	{
		while (!ft_strncmp(token->content, "|", 1) && token)
		{
			if (ft_strncmp(token->content, "|", 1))
			{
				pipe_count++;
			}
			
		}
	}
}

int	isoperator(char *str)
{
	int	i;

	if (ft_strncmp(str, "<", 1))
}