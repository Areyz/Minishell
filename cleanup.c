#include "minishell.h"

/* Freeing list of [env_name, env_val] */
void	ft_clear_env(void *env_node)
{
	t_enviro *content;

	content = (t_enviro *)env_node;
	if (!content)
		return;
	if (content->nam_and_val)
	{
		free(content->nam_and_val[0]);
		free(content->nam_and_val[1]);
		free(content->nam_and_val);
	}
	free(content);
	// content = (t_enviro *) env_node;
	// if (!content)
	// 	return ;
	// if (content->nam_and_val[0])
	// {
	// 	free(content->nam_and_val[0]);
	// 	content->nam_and_val[0] = NULL;
	// }
	// if (content->nam_and_val[1])
	// {
	// 	free(content->nam_and_val[1]);
	// 	content->nam_and_val[1] = NULL;
	// }
	// if (content->nam_and_val)
	// {
	// 	free(content->nam_and_val);
	// 	content->nam_and_val = NULL;
	// }
	// if (content)
	// 	free(content);
	// env_node = NULL;
}
