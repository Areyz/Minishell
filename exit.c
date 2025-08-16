#include "minishell.h"

/* Free global and exit with exit_status */
void	ft_exit(t_global *global)//, int exit_status)
{
	if (global)
		free(global); // is it ok?
	if (global->enviro)
		ft_lstclear(&global->enviro, ft_clear_env);
}
