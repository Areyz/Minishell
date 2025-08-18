/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:02:55 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/17 20:39:54 by mgalecki         ###   ########.fr       */
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
		set_signals_interactive();
		global->input = readline(PROMPT);
		set_signals_noninteractive();
		if (parse_input(global))
			//preapre function for execution
		break;
	}
	//free
}

// void	free_ptr(void **ptr)
// {
// 	if (ptr && *ptr)
// 		free(*ptr);
// 	*ptr = NULL;
// }

// void	free_global(t_global *global)
// {
// 	if (global && global->input)
// 		free_ptr((void **)&global->input);
// }

int	main(int argc, char **argv, char **envp)
{
	t_global	global;
	// envp - contains the list of all env variables
	//global = NULL;
	(void) argc;
	(void) argv;

	if (global_init(&global, envp)) 	//this prepares our 'global' struct
	{
		printf("global init OK\n");	//del
		minishell_loop(&global);
	}

	free((&global)->input);	// zwalnia 1 bajta
	// również wpisując różny input mamy ciągle tyle samo bajtów w leakach

	

	//free((&global)->enviro);
	//	dodając to zmieniło się z
	//	def lost 16 bytes in 1 blocks => 8 bytes in 1 bl
	//	ind lost 36 bytes in 3 blocks => 28 bytes in 3bl

	//free(global); // to też nic nie zmienia, po przeniesieniu do main()'a
					// kompilator nawet krzyczy, że tego się nie zwalnia xD

	free_global(&global); //to zwalnia: def 8 in 1, ind 28 in 3
	return (0);
}
