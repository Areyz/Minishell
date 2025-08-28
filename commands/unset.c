/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:14:37 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/08/28 15:14:38 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	free_elem(t_enviro *elem) // to be checked
{
	if (elem)
	{
		free(elem->nam_and_val[0]);
		free(elem->nam_and_val[1]);
		free(elem->nam_and_val);
		free(elem);
	} //not to many free()?
}

int	ft_unset(t_global *global, t_command *cmd) // to be tested
{
	t_list		*current;
	t_list		*previous;
	t_enviro	*env;

	if (!global || !global->enviro || !cmd || !cmd->arg[1])
		return (0);
	current = global->enviro;
	previous = NULL;
	while (current != NULL) //we go thru list of env
	{
		env = (t_enviro *)current->content;
		if (ft_strncmp(env->nam_and_val[0], cmd->arg[1],
				ft_strlen(env->nam_and_val[0]) + 1) == 0)
		{
			if (!previous) // then we move forward
				global->enviro = current->next;
			else
				previous->next = current->next;
			free_elem(current); //we have to delete this element
			return (0);
		}
		previous = current;
		current = current->next;
	}
	return (0);
}
