/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:13:28 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/09/02 20:52:59 by kjamrosz         ###   ########.fr       */
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
	sep_ptr = ft_strchr(envp, '=');
	if (sep_ptr)
	{
		env_val_length = ft_strlen(sep_ptr + 1);
		env_name_length = env_full_length - env_val_length - 1;
		*env_name = ft_substr(envp, 0, env_name_length);
		*env_value = ft_substr(envp, env_name_length + 1, env_val_length);
	}
	else
		*env_name = ft_strdup(envp);
}

/*Saving envp[i] to t_enviro struct: [env_name, env_value]*/
bool	save_envp_to_list(t_list **list, char *envp)
{
	t_enviro	*content;

	content = ft_calloc(sizeof(t_enviro), 1);
	if (!content)
	{
		ft_lstclear(list, ft_clear_env);
		return (false);
	}
	content->nam_and_val = ft_calloc(sizeof(char *), 2);
	if (!content->nam_and_val)
	{
		ft_lstclear(list, ft_clear_env);
		return (false);
	}
	save_env_nam_and_val(envp, &content->nam_and_val[0],
		&content->nam_and_val[1]);
	if (!content->nam_and_val[0] || !content->nam_and_val[1])
	{
		ft_lstclear(list, ft_clear_env);
		free(content);
		return (false);
	}
	ft_lstadd_back(list, ft_lstnew(content));
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
		if (!save_envp_to_list(&list, envp[i]))
		{
			printf("save_envp_to_global() failed");
			return (false);
		}
	}
	global->enviro = list;
	return (true);
}

void	env_update(t_global *global, const char *name, const char *value)
{
	t_list	*current;

	current = global->enviro;
	while (current)
	{
		if (ft_strncmp(((t_enviro *)current->content)->nam_and_val[0], name,
				ft_strlen(((t_enviro *)current->content)->nam_and_val[0])
				+ 1) == 0)
		{
			if (((t_enviro *)current->content)->nam_and_val[1])
				free(((t_enviro *)current->content)->nam_and_val[1]);
			((t_enviro *)current->content)->nam_and_val[1] = ft_strdup(value);
			return ;
		}
		current = current->next;
	}
}

char	**env_array_from_enviro(t_global *global)
{
	int			i;
	int			list_size;
	char		**result_arr;
	t_list		*node;
	t_enviro	*env;

	i = 0;
	list_size = 0;
	list_size = ft_lstsize(global->enviro);
	node = global->enviro;
	result_arr = ft_calloc(list_size + 1, sizeof(char *));
	while (i < list_size)
	{
		env = (t_enviro *)node->content;
		result_arr[i] = ft_calloc(ft_strlen(env->nam_and_val[0])
				+ ft_strlen(env->nam_and_val[1]) + 2, sizeof(char));
		ft_strlcat(result_arr[i], env->nam_and_val[0], ft_strlen(result_arr[i])
			+ ft_strlen(env->nam_and_val[0]));
		ft_strlcat(result_arr[i], "=", ft_strlen(result_arr[i] + 1));
		ft_strlcat(result_arr[i], env->nam_and_val[1], ft_strlen(result_arr[i])
			+ ft_strlen(env->nam_and_val[1]));
		node = node->next;
		i++;
	}
	return (result_arr);
}
