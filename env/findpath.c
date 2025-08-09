/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:01:28 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/09 22:50:40 by mgolasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_path_env(t_enviro *enviro)
{
	while (enviro != NULL)
	{
		if (!ft_strncmp(enviro->content, "PATH=", 5))
			return (enviro->content + 5);
		enviro = enviro -> next;
	}
	return (NULL);
}

char	*find_command(char *cmd, t_enviro *enviro)
{
	char	*path_env;
	char	**dirs;
	char	*full_path;
	int		i;

	path_env = find_path_env(enviro);
	if (!path_env)
		return (NULL);
	dirs = ft_split(path_env, ':');
	i = 0;
	while (dirs && dirs[i])
	{
		full_path = create_path(dirs[i], cmd);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free_split(dirs);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_split(dirs);
	return (NULL);
}
