#include "../minishell.h"

void	ft_env(t_global *global) //tested to print env - OK
{
	t_list      *env;
    t_enviro    *data;

	env = global->enviro;
    //env->next = global->enviro->next;
	while (env)
	{
        data = (t_enviro *)env->content;
		printf("%s=%s\n", data->nam_and_val[0], data->nam_and_val[1]);
		env = env->next;
	}
}