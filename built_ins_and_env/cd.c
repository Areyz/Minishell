/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:12:40 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/09/02 19:11:09 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	pwd_update(t_global *global, const char *old_dir)
{
	char	*new_dir;

	new_dir = getcwd(NULL, 0);
	env_update(global, "OLDPWD", old_dir);
	if (new_dir)
		env_update(global, "PWD", new_dir);
	else
		perror("cd: getcwd error after chdir");
}

int	ft_cd(t_global *global, t_command *cmd)
{
	char	*path;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("cd: getcwd error");
		return (1);
	}
	if (!cmd->arg[1])
	{
		write(2, "cd: path required\n", 18);
		return (1);
	}
	path = cmd->arg[1];
	if (chdir(path) != 0)
	{
		perror("cd");
		return (1);
	}
	pwd_update(global, cwd);
	return (0);
}
