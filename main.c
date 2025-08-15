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

/*Saving env name and value as one structure*/
bool	save_env_nam_and_val(char *envp, char *env_name, char *env_value)
{
	char		*sep_ptr;
	size_t		env_full_length;
	size_t		env_val_length;
	size_t		env_name_length;

	env_full_length = ft_strlen(envp); //calculate length of full envp

	sep_ptr = ft_strchr(envp, '='); //we find the firs occurence of '='
	//sep_ptr is pointing at first '='

	env_val_length = ft_strlen(sep_ptr + 1); // calculate length of value

	env_name_length = env_full_length - env_val_length - 1; //length of env_name
}

/*Saving envp[i] to t_enviro struct: [env_name, env_value]*/
bool	save_envp_to_global(t_global *global, char *envp)
{
	t_enviro	*content;

	content = ft_calloc(sizeof(t_enviro), 1);//allocate mem for [name,val]
	if (!content)
	{
		//free
		return (false);
	}
	content->nam_and_val = ft_calloc(sizeof(char *), 2); //alloc for two strings
	if (!content->nam_and_val)
	{
		//free
		return (false);
	}
	save_env_nam_and_val(envp, &content->nam_and_val[0], &content->nam_and_val[1]);
	//TODO: check if save_env_nam_and_val() works properly

	//take each env_var and save its name and value separately to t_enviro
	//make a list of t_enviro
	//save the list to global (global->enviro = list;)
	return (true);
}

/*Creating list of t_enviro elements*/
bool	env_init(t_global *global, char **envp)
{
	t_list	*list; //list from libft
	int		i;

	list = NULL;
	i = -1;
	while (envp[++i])
	{
		if(!save_envp_to_global(&global, envp))	//TODO
		{
			//free or sth
			printf("save_envp_to_global() failed");
			return (false);
		}
	}
	global->enviro = list; //saving all env vars as a list in 'global'
	//each elem of the list is [env_name, env_value] (t_enviro)
	return (true);
}

bool	global_init(t_global *global, char **envp)
{

	if(!env_init(&global, envp))
	{
		printf("env_init() failed");
		exit(42);
		//add free()
	}

	//other initialization for our 'global' struct

	return (true);
}


//Main function - to do - add Sigur loop and commands and states (ctrl - c etc)
int	main(int argc, char **argv, char **envp)
{
	t_global	global;
	// envp - contains the list of all env variables
	//global = NULL; //no need to initialize
	(void) argc;
	(void) argv;
	if(global_init(&global, envp)) 	//this prepares our 'global' struct
	{
		//run the loop
	}




	//lexer(argv);


	// loop
	char	*r_line;
	while (42)
	{
		// 1) read
		r_line = readline("minishell >> ");
		printf("%s\n", r_line); //for tests
		lexer(r_line);

		// 2) lexer/parser
		// 3) execute
	}

	return (0);
}
