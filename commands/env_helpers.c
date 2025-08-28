#include "../minishell.h"

void	env_update(t_global *global, const char *name, const char *value)
{
	t_enviro	*current;

	current = global->enviro;
	while (current)
	{
		if (ft_strncmp(current->content->nam_and_val[0], name, 
			ft_strlen(current->content->nam_and_val[0]) + 1) == 0)
		{
			if (current->content->nam_and_val[1])
				free(current->content->nam_and_val[1]);
			current->content->nam_and_val[1] = ft_strdup(value);
			return ;
		}
		current = current->next;
	}
}