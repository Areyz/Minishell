/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:00:38 by mgalecki          #+#    #+#             */
/*   Updated: 2025/09/01 19:10:37 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	alloc_commands(t_global *global)
{
	int	i;
	int pipes;
	
	i = 0;
	pipes = 0;
	while (global->token_array[i])
	{
		if (ft_strncmp(global->token_array[i], "|", 1) == 0)
			pipes++;
		i++;
	}
	if (i == 0)
	{
		global->command = NULL;
		global->comand_nbr = 0;
		return ;
	}
	global->command = safe_malloc(sizeof(t_command) * (pipes + 1));
	global->comand_nbr = pipes + 1;
}