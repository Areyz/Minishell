/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:02:55 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/11 17:23:23 by mgolasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Initializing global struct*/
bool	global_init(t_global *global, char **envp)
{
	//printf("inside > global_init()\n");	//del
	if(!env_init(global, envp))
	{
		printf("env_init() failed");
		exit(42);
		//add free()
	}

	//initialization of other elements of our 'global' struct

	return (true);
}

void minishell_loop(t_global *global)
{
	printf("entered minishell_loop()\n");
	while (42)
	{
		//take care of signals etc
		global->input = readline(PROMPT);
		break;
	}
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
