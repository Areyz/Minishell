/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:52:24 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/09 22:50:43 by mgolasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**rebuild_env(t_enviro *enviro)
{
	char		**ret;
	t_enviro	*tmp;
	int			i;

	tmp = enviro;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	ret = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (enviro != NULL)
	{
		ret[i] = (ft_strdup(enviro->content));
		enviro = enviro->next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

//initialization of environmental "tokens"
t_enviro	*ft_lstnew_env(char *content)
{
	t_enviro	*elem;

	elem = malloc(sizeof(t_enviro));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

t_enviro	*env_init(char *envp[])
{
	t_enviro	*start;
	t_enviro	*new_node;
	t_enviro	*current;
	int			i;

	i = 0;
	start = NULL;
	while (envp[i])
	{
		new_node = ft_lstnew_env(ft_strdup(envp[i]));
		if (!start)
		{
			start = new_node;
			current = start;
		}
		else
		{
			current->next = new_node;
			current = new_node;
		}
		i++;
	}
	return (start);
}
