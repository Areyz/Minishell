/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:13:28 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/08/28 15:13:29 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*Saving env name and value as one structure*/
void	save_env_nam_and_val(char *envp, char **env_name, char **env_value)
{
	char		*sep_ptr;
	size_t		env_full_length;
	size_t		env_val_length;
	size_t		env_name_length;

	env_full_length = ft_strlen(envp);
	sep_ptr = NULL;
	// strchr will return ptr to '\0' on the end of a string
	// if the character won't be found
	sep_ptr = ft_strchr(envp, '=');
	if (sep_ptr)
	{
		env_val_length = ft_strlen(sep_ptr + 1);
		env_name_length = env_full_length - env_val_length - 1;

		*env_name = ft_substr(envp, 0, env_name_length);
		*env_value = ft_substr(envp, env_name_length + 1, env_val_length);
	}
	else //in case if some env[i] will not contain '=' for some reason
		*env_name = ft_strdup(envp);
}

/*Saving envp[i] to t_enviro struct: [env_name, env_value]*/
bool	save_envp_to_list(t_list **list, char *envp)
{
	//printf("\ninside > save_envp_to_list()\n");	//del
	t_enviro	*content;

	content = ft_calloc(sizeof(t_enviro), 1);//allocate mem for [name,val]
	if (!content)
	{
		ft_lstclear(list, ft_clear_env);
		return (false);
	}
	content->nam_and_val = ft_calloc(sizeof(char *), 2); //alloc for two strings
	if (!content->nam_and_val)
	{
		ft_lstclear(list, ft_clear_env);
		return (false);
	}
	save_env_nam_and_val(envp, &content->nam_and_val[0], &content->nam_and_val[1]);
	if (!content->nam_and_val[0] || !content->nam_and_val[1])
	{
		ft_lstclear(list, ft_clear_env);
		free(content);
		return (false);
	}
	// condition checking env_name == '_', path to env
	ft_lstadd_back(list, ft_lstnew(content)); // adding content to the list
	return (true);
}

/*Creating list of t_enviro elements*/
bool	env_init(t_global *global, char **envp)
{
	t_list	*list;
	int		i;

	list = NULL;
	i = -1;
	while (envp[++i])
	{
		if(!save_envp_to_list(&list, envp[i]))
		{
			// here we shouldn't free() (probably)
			// because save_envp_to_list() already does it
			printf("save_envp_to_global() failed");
			return (false);
		}
		//break;
	}
	global->enviro = list;	//OK
	return (true);
}
