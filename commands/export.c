/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:14:12 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/08/28 15:14:15 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_if_env_exists(t_command *cmd, t_list *current)
{
	t_enviro	*env;
	t_enviro	*new_env;

	save_env_nam_and_val(cmd->arg[1], &new_env->nam_and_val[0],
				&new_env->nam_and_val[0]);
	while (current != NULL)
	{
		env = ((t_enviro *)current->content);
		if (ft_strcmp(env->nam_and_val[0], new_env->nam_and_val[0]) == 0)
		//we compare names, if we already have this env
		{
			if (env->nam_and_val[1])//if it has value
				free(env->nam_and_val[1]);
			env->nam_and_val[1] = new_env->nam_and_val[1];
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	ft_export(t_global *global, t_command *cmd)
{
	t_list	*current;

	current = global->enviro;
	if (!current) // if list of env is empty
		current = save_envp_to_list(current, cmd->arg[1]);
	else
	{
		if (check_if_env_exists(cmd, current) == 0)
			return (0);
		while (current->next != NULL)
			current = current->next;
		if (cmd->arg[1] && ft_strchr(cmd->arg[1], '=')) //if there is a command that containd '='
			current->next = save_envp_to_list(current, cmd->arg[1]);
	}
	return (0);
}
