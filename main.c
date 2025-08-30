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
		global->input = readline(PROMPT);
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
		printf("global init OK\n");	//del
		init_signalz();
		rl_catch_signals = 0;
		minishell_loop(&global);
	}

	free((&global)->input);
	free_global(&global);
	return (0);
}
