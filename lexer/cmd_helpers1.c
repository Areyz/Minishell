/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_helpers1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:24:03 by mgalecki          #+#    #+#             */
/*   Updated: 2025/09/01 20:18:21 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redirect(char *arg)
{
	if (ft_strncmp(arg, ">", 2) == 0 || ft_strncmp(arg, "<", 2) == 0
		|| ft_strncmp(arg, ">>", 3) == 0 || ft_strncmp(arg, "<<", 3) == 0)
		return (1);
	return (0);
}

void	init_commands(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->comand_nbr)
	{
		global->command[i].name = NULL;
		global->command[i].arg = NULL;
		global->command[i].arg_num = 0;
		global->command[i].redir_count = 0;
		global->command[i].redir_count = NULL;
		i++;
	}
}