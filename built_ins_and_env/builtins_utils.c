/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:55:17 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/09/01 21:11:10 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_quit(t_global *global, int exit_code)
{
	free_all(global);
	ft_clear_env_list(global->enviro);
	exit(exit_code);
}

int	ft_builtins(t_global *global, int cmd_n)
{
	int	exit_code;

	exit_code = 0;
	if (!ft_strncmp(global->command[cmd_n].arg[0], "pwd", 4))
		exit_code = ft_pwd();
	else if (!ft_strncmp(global->command[cmd_n].arg[0], "export", 6))
		exit_code = ft_export(global, &global->command[cmd_n]);
	else if (!ft_strncmp(global->command[cmd_n].arg[0], "unset", 6))
		exit_code = ft_unset(global, &global->command[cmd_n]);
	else if (!ft_strncmp(global->command[cmd_n].arg[0], "env", 4))
		exit_code = ft_env(global);
	else if (!ft_strncmp(global->command[cmd_n].arg[0], "exit", 5))
		ft_exit(global);
	else if (!ft_strncmp(global->command[cmd_n].arg[0], "cd", 3))
		exit_code = ft_cd(global, &global->command[cmd_n]);
	else if (!ft_strncmp(global->command[cmd_n].arg[0], "echo", 5))
		exit_code = ft_echo(&global->command[cmd_n]);
	else
		return (-1);
	global->last_exit_code = exit_code;
	if (global->comand_nbr > 1)
		ft_quit(global, exit_code);
	return (exit_code);
}
