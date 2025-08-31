/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:35:58 by mgalecki          #+#    #+#             */
/*   Updated: 2025/08/31 17:36:01 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
get_and_validate_input() - showing the shell prompt,reading user 
input with readline, checking if the input is valid, returning a 
status code so the main loop knows what to do next.
*/
int	get_and_validate_input(t_global *global)
{
	global->input = readline(PROMPT);
	if (!global->input)
	{
		printf("\nExiting...\n");
		return (0);
	}
	if (ft_strlen(global->input) == 0)
	{
		free(global->input);
		return (2);
	}
	add_history(global->input);
	return(1);
}

int	process_and_execute(t_global *global)
{
	global->token_array = tokenize(global);
	if (validate_pipe_syntax(global) == 1)
	{
		global->last_exit_code = 2;
		safefree(global->input);
		free_string_array(global->token_array);
		return (2);
	}
	lexer(global);
	if (global->command_nbr > 0 && global->command[0].arg
		&& global->command[0].arg[0] && global->command_nbr < 2130)
	{
		if (global->command_nbr == 1)
		{
			if (ft_builtins(global, 0) == -1)
				launch_command(global);
		}
		else
			launch_command(global);
	}
	free_all(global);
	return (1);
}
