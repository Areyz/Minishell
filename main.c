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

t_global	global_init(char **envp)
{
	t_enviro	*enviro;

	enviro = env_init(envp);
	global->enviro = enviro;
	return (global);
}

//Main function - to do - add Sigur loop and commands and states (ctrl - c etc)
int	main(int argc, char *argv[], char *envp[])
{
	t_global	global;
	
	//global = NULL;
	(void) argc;
	global = global_init(envp);
	lexer(argv);

	//
	while (42)
	{
		// 1) read
		// 2) lexer/parser
		// 3) execute
		
	}

	return (0);
}
