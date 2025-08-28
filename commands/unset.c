#include "../minishell.h"

static void	free_elem(t_environ *elem) // CHECK THIS!!!
{
	if (elem)
	{
		free(elem->content->nam_and_val[0]);
		free(elem->content->nam_and_val[1]);
		free(elem->content->nam_and_val);
		free(elem->content);
		free(elem);
	} //there are probably to many freeses XDD
}

int	ft_unset(t_global *global, t_command *cmd) // to be tested
{
	t_enviro	*current;
	t_enviro	*previous;

	if (!global->enviro)
		return (0);
	current = global->enviro;
	previous = NULL;
	while (current != NULL) //we go thru list of env
	{
		if (ft_strncmp(current->content->nam_and_val[0], cmd->arg[1],
				!ft_strlen(current->content->nam_and_val[0]) + 1))
			// we check if name DOES NOT match
		{
			if (!previous) // then we move forward
				global->enviro = current->next;
			else
				previous->next = current->next;
			free_elem(current); //we have to delete this element
			return (0);
		}
		previous = current;
		current = current->next;
	}
	return (0);
}