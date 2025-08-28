/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:12:40 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/08/28 15:12:43 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	pwd_update(t_global *global, const char *old_dir)
{
	char	*new_dir;	//[4096];

	new_dir = getcwd(NULL, 0);
	env_update(global, "OLDPWD", old_dir);
	if (new_dir) // != NULL
		env_update(global, "PWD", new_dir);
	else
		perror("cd: getcwd error after chdir");
}

int	ft_cd(t_global *global, t_command *cmd) // to be tested
{
	char	*path;
	// char	cwd[4096];	//it's the max size of path in linux
	char	*cwd;

	cwd = getcwd(NULL, 0);

	if (!cwd) // == NULL
	{
		perror("cd: getcwd error");
		return (1);
	}
	if (!cmd->arg[1])
	{
		write(2, "cd: path required\n", 18);
		// 2 == stderr
		return (1);
	}
	path = cmd->arg[1];
	if (chdir(path) != 0)  //On success, zero is returned.
	{
		perror("cd");
		return (1);
	}
	pwd_update(global, cwd);
	return (0);
}
