#include "minishell.h"

/* Free all global's variables besides enviro */
void	free_global(t_global *global)
{
	// if (global)
	// 	free_global(global);
	if (global->enviro)
		ft_lstclear(&global->enviro, ft_clear_env);
}
