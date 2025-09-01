/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:00:38 by mgalecki          #+#    #+#             */
/*   Updated: 2025/09/01 19:51:32 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	alloc_commands(t_global *global)
{
	int	i;
	int pipes;
	
	i = 0;
	pipes = 0;
	while (global->token_array[i])
	{
		if (ft_strncmp(global->token_array[i], "|", 1) == 0)
			pipes++;
		i++;
	}
	if (i == 0)
	{
		global->command = NULL;
		global->comand_nbr = 0;
		return ;
	}
	global->command = safe_malloc(sizeof(t_command) * (pipes + 1));
	global->comand_nbr = pipes + 1;
	init_commands(global);
	alloc_args(global);
}

void	hanlde_pipe_token(t_global *global, int *cmd_i, int *arg_i, int *tkn_i)
{
	global->command[*cmd_i].arg = safe_malloc(sizeof(char *) * (*arg_i + 1));
	global->command[*cmd_i].arg_num = *arg_i;
	(*cmd_i)++;
	*arg_i = 0;
	(*tkn_i)++;
}

void	alloc_args(t_global *global)
{
	int	tkn_i;
	int	arg_i;
	int	cmd_i;

	init_iterators(&tkn_i, &arg_i, &cmd_i);
	while (global->token_array[tkn_i])
	{
		if (ft_strncmp(global->token_array[tkn_i], '|', 1) == 0)
		{
			handle_pipe_token(global, &cmd_i, &arg_i, &tkn_i);
			continue ;
		}
		if (global->token_array[tkn_i + 1] == NULL)
		{
			arg_i++;
			global->command[cmd_i].arg = safe_malloc(sizeof(char *) * (arg_i + 1));
			global->command[cmd_i].arg_num = arg_i;
			break;
		}
		tkn_i++;
		arg_i++;
	}
}