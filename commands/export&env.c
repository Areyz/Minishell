/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export&env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 22:10:13 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/11 17:23:38 by mgolasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export(t_global *global, t_token *token)
{
	t_enviro	*enviro;
	t_enviro	*lst;
	char		*to_copy;

	enviro = global->enviro;
	if (export_replace(global, token))
		return ;
	else
	{
		lst = malloc(sizeof(t_enviro));
		if (!lst)
			return ;
		while (enviro != NULL && enviro -> next != NULL)
			enviro = enviro->next;
		lst->content = ft_strdup(token->history);
		enviro->next = lst;
		lst->next = NULL;
	}
}

int	export_replace(t_global *global, t_token *token)
{
	char		*to_replace;
	char		*to_compare;
	t_enviro	*enviro;

	enviro = global->enviro;
	to_replace = get_key(token->history);
	while (enviro != NULL)
	{
		to_compare = get_key(enviro->content);
		if ((ft_strncmp(to_compare, to_replace, ft_strlen(to_replace)) == 0))
		{
			free(enviro->content);
			enviro->content = ft_strdup(token->history);
			if (!enviro->content)
				error_exit(global, ENOMEM);
			free(to_compare);
			free(to_replace);
			return (1);
		}
		free(to_compare);
		enviro = enviro->next;
	}
	free(to_replace);
	return (0);
}

char	*get_key(char *str)
{
	int		i;
	int		l;
	char	*key;

	i = 0;
	l = 0;
	while (str[i] != '=' && str[i])
		i++;
	key = malloc(i + 1);
	while (l < i)
	{
		key[l] = str[l];
		l++;
	}
	key[l] = '\0';
	return (key);
}

void	env(t_global *global)
{
	t_enviro	*enviro;

	enviro = global->enviro;
	while (enviro)
	{
		printf("%s", enviro->content);
		enviro = enviro->next;
	}
}