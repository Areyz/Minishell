/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 22:10:13 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/06 22:53:21 by mgolasze         ###   ########.fr       */
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
	while (enviro != NULL)
		enviro = enviro->next;
	to_copy = ft_strdup(token->history);
	lst.content = to_copy;
	enviro->next = lst;
	lst->next = NULL;
}