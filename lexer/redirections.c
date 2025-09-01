/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:11:58 by mgalecki          #+#    #+#             */
/*   Updated: 2025/09/01 20:33:15 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_filename(t_command *cmd, int redir_i, int arg_i)
{
	if (cmd->arg[arg_i] == NULL)
	{
		cmd->redir[redir_i].type = INVALID;
		return ;
	}
	cmd->redir[redir_i].file_name
		= ft_strdup(cmd->arg[arg_i]);
	if (!cmd->redir[redir_i].file_name)
	{
		perror("malloc");
		return ;
	}
}

void	alloc_redir(t_global *global, int cmd_i)
{
	int	redirs;
	int	arg_i;

	redirs = 0;
	arg_i = 0;
	while (global->command[cmd_i].arg[arg_i])
	{
		if (is_redirect(global->command[cmd_i].arg[arg_i]))
			redirs++;
		arg_i++;
	}
	if (redirs == 0)
	{
		global->command[cmd_i].redir = NULL;
		return ;
	}
	global->command[cmd_i].redir = safe_malloc(sizeof(t_redir) * redirs);
	init_redirs(global, cmd_i, redirs);
}

void	process_redirection(t_command *cmd, char *arg, int redir_i, int arg_i)
{
	redir_type(&cmd->redir[redir_i], arg);
	redir_filename(cmd, redir_i, arg_i + 1);
}

void	redir_parse(t_global *global)
{
	int	cmd_i;
	int	arg_i;

	cmd_i = 0;
	arg_i = 0;
	while (cmd_i < global->comand_nbr)
	{
		while (global->command[cmd_i].arg[arg_i])
		{
			if (global->command[cmd_i].arg[arg_i][0] == '<'
				|| global->command[cmd_i].arg[arg_i][0] == '>')
			{
				if (global->command[cmd_i].redir == NULL)
					alloc_redir(global, cmd_i);
				process_redirection(&global->command[cmd_i],
					global->command[cmd_i].arg[arg_i],
					global->command[cmd_i].redir_count, arg_i);
				global->command[cmd_i].redir_count++;
			}
			arg_i++;
		}
		arg_i = 0;
		cmd_i++;
	}
}