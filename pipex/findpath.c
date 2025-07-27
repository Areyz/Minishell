/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:01:28 by mgolasze          #+#    #+#             */
/*   Updated: 2025/06/29 18:44:39 by mgolasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_command(char *cmd, char **env)
{
	char	*path_env;
	char	**dirs;
	char	*full_path;
	int		i;

	path_env = find_path_env(env);
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
