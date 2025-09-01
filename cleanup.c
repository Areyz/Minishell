/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:46:09 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/09/01 19:46:11 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clear_env_list(t_list *node)
{
	t_list		*node;
	t_enviro	*env;
	while (node)
	{
		content = (t_enviro *)node->content;
		if (!content)
			return;
		if (content->nam_and_val)
		{
			free(content->nam_and_val[0]);
			free(content->nam_and_val[1]);
			free(content->nam_and_val);
		}
		free(content);
			node = node->next;
	}
	free(node);
}

/* Freeing list of [env_name, env_val] */
void	ft_clear_env(void *env_node)
{
	t_enviro *content;

	content = (t_enviro *)env_node;
	if (!content)
		return;
	if (content->nam_and_val)
	{
		free(content->nam_and_val[0]);
		free(content->nam_and_val[1]);
		free(content->nam_and_val);
	}
	free(content);
	// content = (t_enviro *) env_node;
	// if (!content)
	// 	return ;
	// if (content->nam_and_val[0])
	// {
	// 	free(content->nam_and_val[0]);
	// 	content->nam_and_val[0] = NULL;
	// }
	// if (content->nam_and_val[1])
	// {
	// 	free(content->nam_and_val[1]);
	// 	content->nam_and_val[1] = NULL;
	// }
	// if (content->nam_and_val)
	// {
	// 	free(content->nam_and_val);
	// 	content->nam_and_val = NULL;
	// }
	// if (content)
	// 	free(content);
	// env_node = NULL;
}

void	free_string_array(char **arg)
{
	int	i;

	if (!arg)
		return ;
	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}

void	free_commands(t_global *global)
{
	int	i;

	if (!global->command)
		return ;
	i = 0;
	while (i < global->command_nbr)
	{
		free_string_array(global->command[i].arg);
		if (global->command[i].redir)
		{
			free(global->command[i].redir->filename);
			free(global->command[i].redir);
		}
		i++;
	}
	free(global->command);
	global->command = NULL;
	global->command_nbr = 0;
}

void	safefree(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	free_all(t_global *global)
{
	if(global->input)
	{
		free(global->input);
		global->input = NULL;
	}
	if (global->command)
	{
		free_commands(global);
		global->command = NULL;
	}
	if (global->token_arr)
	{
		free_string_array(global->token_arr);
		global->token_arr = NULL;
	}
}