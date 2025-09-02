/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:14:12 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/09/02 20:52:45 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	allocate_mem(t_enviro **new_env)
{
	*new_env = malloc(sizeof(t_enviro *));
	if (!(*new_env))
		printf("error - malloc");
	(*new_env)->nam_and_val = malloc(2 * sizeof(char *));
	if (!((*new_env)->nam_and_val))
		printf("error - malloc");
	(*new_env)->nam_and_val[0] = malloc(sizeof(char *));
	if (!((*new_env)->nam_and_val[0]))
		printf("error - malloc");
	(*new_env)->nam_and_val[1] = malloc(sizeof(char *));
	if (!((*new_env)->nam_and_val[1]))
		printf("error - malloc");
}

static int	check_if_env_exists(t_command *cmd, t_list *current)
{
	t_enviro	*env;
	t_enviro	*new_env;

	new_env = NULL;
	allocate_mem(&new_env);
	save_env_nam_and_val(cmd->arg[1], &new_env->nam_and_val[0],
		&new_env->nam_and_val[0]);
	while (current != NULL)
	{
		env = ((t_enviro *)current->content);
		if ((ft_strncmp(env->nam_and_val[0], new_env->nam_and_val[0],
					ft_strlen(new_env->nam_and_val[0])) == 0))
		{
			if (env->nam_and_val[1])
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
	if (!current)
	{
		if (!save_envp_to_list(&current, cmd->arg[1]))
			printf("error\n");
	}
	else
	{
		if (check_if_env_exists(cmd, current) == 0)
			return (0);
		while (current->next != NULL)
			current = current->next;
		if (cmd->arg[1] && ft_strchr(cmd->arg[1], '='))
			save_envp_to_list(&current->next, cmd->arg[1]);
	}
	return (0);
}
