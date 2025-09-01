/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:57:05 by mgalecki          #+#    #+#             */
/*   Updated: 2025/09/01 19:09:02 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		ft_putchar_fd("Error: Memory allocation failed\n", 2);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

/*Initializing global struct*/
bool	global_init(t_global *global, char **envp)
{
	if(!env_init(global, envp))
	{
		ft_putstr_fd("env_init failed\n", 2);
		exit(EXIT_FAILURE);
	}
	//initialization of other elements of our 'global' struct
	global->input = NULL;
	return (true);
}

/*
get_and_validate_input - displays the prompt (via readline), 
reads the user’s command, 
checks if the input is valid (not empty, not only spaces, etc.) 
and returns a status code telling what to do next.
If the status is 0, it means the user wants 
to exit (for example, typing exit or hitting Ctrl+D).
If the status is 2, it means skip this iteration and 
go back to prompting the user again.
(This could happen if the input was empty, 
contained only spaces, or had a syntax error.)
If process_and_execute reports 2, the loop just skips 
to the next prompt instead of continuing execution.
*/

void minishell_loop(t_global *global)
{
	int	loop_status;

	while (42)
	{
		loop_status = get_and_validate_input(global);
		if (loop_status == 0)
			break;
		if (loop_status == 2)
			continue;
		loop_status = process_and_execute(global);
		if (loop_status == 2)
			continue;
	}
	//free
}

/*
init_signalz() - This function sets up signal handling
rl_catch_signals = 0; - setup for handle signals by sigaction
*/
int	main(int argc, char **argv, char **envp)
{
	t_global	global;
	// envp - contains the list of all env variables
	//global = NULL;
	(void) argc;
	(void) argv;

	if (global_init(&global, envp)) 	//this prepares our 'global' struct
	{
		init_signalz();
		rl_catch_signals = 0;
		minishell_loop(&global);
	}

	free((&global)->input);
	free_global(&global);
	return (0);
}
