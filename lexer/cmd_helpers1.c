/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_helpers1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:24:03 by mgalecki          #+#    #+#             */
/*   Updated: 2025/09/01 20:48:53 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_redir(t_global *global, int arg_i, int cmd_i)
{
	char	**new_args;
	int		new_i;
	int		old_i;

	new_i = 0;
	old_i = 0;
	global->command[cmd_i].arg_num -= 2;
	new_args = safe_malloc(sizeof(char *)
			* (global->command[cmd_i].arg_num + 1));
	new_args[global->command[cmd_i].arg_num] = NULL;
	while (new_i < global->command[cmd_i].arg_num)
	{
		if (old_i != arg_i && old_i != arg_i + 1)
		{
			new_args[new_i] = ft_strdup(global->command[cmd_i].arg[old_i]);
			new_i++;
			old_i++;
		}
		else
			old_i++;
	}
	free_string_array(global->command[cmd_i].arg);
	global->command[cmd_i].arg = new_args;
}

int	is_redirect(char *arg)
{
	if (ft_strncmp(arg, ">", 2) == 0 || ft_strncmp(arg, "<", 2) == 0
		|| ft_strncmp(arg, ">>", 3) == 0 || ft_strncmp(arg, "<<", 3) == 0)
		return (1);
	return (0);
}

void	cut_args(t_global *global)
{
	int	arg_i;
	int	cmd_i;

	arg_i = 0;
	cmd_i = 0;
	while (cmd_i < global->comand_nbr)
	{
		while (global->command[cmd_i].arg[arg_i])
		{
			if (is_redirect(global->command[cmd_i].arg[arg_i]))
			{
				if (global->command[cmd_i].arg[arg_i + 1] != NULL)
				{
					del_redir(global, arg_i, cmd_i);
					arg_i = 0;
				}
				else
					arg_i++;
			}
			else
				arg_i++;
		}
		cmd_i++;
		arg_i = 0;
	}
}

void	init_commands(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->comand_nbr)
	{
		global->command[i].name = NULL;
		global->command[i].arg = NULL;
		global->command[i].arg_num = 0;
		global->command[i].redir_count = 0;
		global->command[i].redir_count = NULL;
		i++;
	}
}