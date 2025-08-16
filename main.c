/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:02:55 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/16 18:50:56 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Initializing global struct*/
bool	global_init(t_global *global, char **envp)
{
	//printf("inside > global_init()\n");	//del
	if(!env_init(global, envp))
	{
		ft_putstr_fd("env_init failed\n", 2);
		exit(EXIT_FAILURE);
	}

	//initialization of other elements of our 'global' struct
	global->input = NULL;

	return (true);
}

void minishell_loop(t_global *global)
{
	while (42)
	{
		//set_signals_interactive();
		global->input = readline(PROMPT);
		//set_signals_noninteractive();
		break;
	}
	//free
	free_global(global);
}

void	free_ptr(void **ptr)
{
	if (ptr && *ptr)
		free(*ptr);
	*ptr = NULL;
}

void	free_global(t_global *global)
{
	if (global && global->input)
		free_ptr((void **)&global->input);
}

//Main function - to do - add Sigur loop and commands and states (ctrl - c etc)
int	main(int argc, char **argv, char **envp)
{
	t_global	global;
	// envp - contains the list of all env variables
	//global = NULL;
	(void) argc;
	(void) argv;
	
	if(global_init(&global, envp)) 	//this prepares our 'global' struct
	{
		printf("global init OK\n");	//del
		minishell_loop(&global);
	}

	//lexer(argv);

	// loop - put it in separate function
	/*
	char	*r_line;
	while (42)
	{
		// 1) read
		r_line = readline("minishell >> ");
		printf("%s\n", r_line); //for tests
		//lexer(r_line);

		// 2) lexer/parser
		// 3) execute
	}
		*/
	return (0);
}
