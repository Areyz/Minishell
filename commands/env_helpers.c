/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:13:13 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/08/28 15:13:15 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env_update(t_global *global, const char *name, const char *value)
{
	t_list	*current;

	current = global->enviro;
	while (current)
	{
		if (ft_strncmp(((t_enviro *)current->content)->nam_and_val[0], name, 
			ft_strlen(((t_enviro *)current->content)->nam_and_val[0]) + 1) == 0)
		{
			if (((t_enviro *)current->content)->nam_and_val[1])
				free(((t_enviro *)current->content)->nam_and_val[1]);
			((t_enviro *)current->content)->nam_and_val[1] = ft_strdup(value);
			return ;
		}
		current = current->next;
	}
}
