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

t_global	global;
/*
t_global	global_init(char **envp)
{
	t_enviro	*enviro;

	enviro = env_init(envp);
	global.enviro = enviro;
	return (global);
}
*/

//Main function - to do - add Sigur loop and commands and states (ctrl - c etc)
int	main(int argc, char **argv, char **envp)
{	
	//global = NULL;
	(void) argc;
	(void) argv; //temporarily added for tests
	(void) envp; //temporarily added for tests
	//global = global_init(envp); //to be uncommented
	//lexer(argv);

	// loop
	char	*r_line;
	while (42)
	{
		// 1) read
		r_line = readline("minishell >> ");
		printf("%s\n", r_line); //for tests

		// 2) lexer/parser
		// 3) execute
	}

	return (0);
}
