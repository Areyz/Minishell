#include "minishell.h"

/*
get_and_validate_input() - showing the shell prompt,reading user 
input with readline, checking if the input is valid, returning a 
status code so the main loop knows what to do next.
*/
static int	get_and_validate_input(t_global *global)
{
	global->input = readline("\033[22;33m$minishell> \033[0m");
	if (!global->input)
	{
		printf("\nExiting...\n");
		return (0);
	}
	if (ft_strlen(global->input) == 0)
	(
		free(global->input);
		return (2);
	)
	add_history(global->input);
	return(1);
}

static int	process_and_execute(t_global *global)
{
	global->token_array = tokenize(global);
}