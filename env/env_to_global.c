#include "../minishell.h"

/*Saving env name and value as one structure*/
bool	save_env_nam_and_val(char *envp, char **env_name, char **env_value)
{
	//printf("inside > save_env_nam_and_val()\n");	//del
	char		*sep_ptr;
	size_t		env_full_length;
	size_t		env_val_length;
	size_t		env_name_length;

	env_full_length = ft_strlen(envp); //calculate length of full envp
	sep_ptr = ft_strchr(envp, '='); //we find the firs occurence of '='
	//sep_ptr is pointing at first '='
	env_val_length = ft_strlen(sep_ptr + 1); // calculate length of value
	env_name_length = env_full_length - env_val_length - 1; //length of env_name

	*env_name = ft_substr(envp, 0, env_name_length);
	*env_value = ft_substr(envp, env_name_length + 1, env_val_length);
	return (true);
	//additional condition if there would be no '=' in envp[i]
	//add some checks to see if everything works correctly
}

/*Saving envp[i] to t_enviro struct: [env_name, env_value]*/
bool	save_envp_to_list(t_list **list, char *envp)
{
	//printf("\ninside > save_envp_to_list()\n");	//del
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
	if (!content->nam_and_val[0] || !content->nam_and_val[1])
	{
		//free
		printf("save_env_nam_and_val() doesn't work properly\n");
		return (false);
	}


	ft_lstadd_back(list, ft_lstnew(content)); // adding content to the list

	// TEST
	t_list *last = ft_lstlast(*list);
	printf("name  : %s\n", ((t_enviro *)last->content)->nam_and_val[0]);	//
	printf("value : %s\n", ((t_enviro *)last->content)->nam_and_val[1]);	//
	// END OF TEST



	//save the list to global (global->enviro = list;)
	return (true);
}

/*Creating list of t_enviro elements*/
bool	env_init(t_global *global, char **envp)
{
	//printf("inside > env_init()\n");	//del
	t_list	*list; //list from libft
	int		i;

	list = NULL;
	i = 0;
	while (envp[i])
	{
		//printf("\ni = %d\n", i);	//del
		//printf("envp[%d] = %s\n", i, envp[i]);
		if(!save_envp_to_list(&list, envp[i]))	//TODO
		{
			//free or sth
			printf("save_envp_to_global() failed");
			return (false);
		}
		i++;
	}
	//printf("finished loop\n");

	global->enviro = list;	//OK

	//each elem of the list is [env_name, env_value] (t_enviro)
	return (true);
}