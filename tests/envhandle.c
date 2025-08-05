/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:29:52 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/05 19:56:41 by mgolasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct s_enviro
{
	char			*content;
	struct s_enviro *next;
}	t_enviro;

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

int	main(int argc, char *argv[], char *envp[])
{
	t_enviro *test;

	(void)argc;
	(void)argv;
	test = env_init(envp);
	while (test->next != NULL)
	{
		printf("%s\n", test->content);
		test = test->next;
	}
	return (0);
}
