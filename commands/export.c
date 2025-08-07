/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 22:10:13 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/07 21:55:18 by mgolasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export(t_global *global, t_token *token)
{
	t_enviro	*enviro;
	t_enviro	*lst;
	char		*to_copy;

	lst = malloc(sizeof(t_enviro));
	if (!lst)
		return ;
	enviro = global->enviro;
	if (export_replace(global, token))
		return ;
	else
	{
		while (enviro -> next != NULL)
			enviro = enviro->next;
		to_copy = ft_strdup(token->history);
		lst.content = to_copy;
		enviro->next = lst;
		lst->next = NULL;
	}
}

int	export_replace(t_global *global, t_token *token)
{
	char	*to_replace;

	if (ft_strncmp(global->content, token->history, ft_strlen(token->history)))
		to_replace = get_key(token->history);
	while(token -> next != NULL)
	{
		if (ft_strncmp(global->content, to_replace, ft_strlen(to_replace)))
		{
			global->content = realloc(sizeof(char *) * (ft_strlen(to_replace)));
			if (!global->content)
				error_exit(global, ENOMEM);
			return (1);
		}
		global = global->next;
	}
	return (0);
}

char	*get_key(char *str)
{
	int		i;
	char	*key;

	i = 0;
	while (str[i] != "=" && str[i])
		i++;
	key = ft_strldup(str, i);
	return (key);
}