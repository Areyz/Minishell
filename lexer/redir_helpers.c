/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:19:56 by mgalecki          #+#    #+#             */
/*   Updated: 2025/09/01 21:17:58 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redir_type(t_redir *redir_struct, char *arg)
{
	int	char_i;

	char_i = 0;
	if (arg[char_i] == '<')
	{
		char_i++;
		if (arg[char_i] == '<')
			redir_struct->type = HEREDOC;
		else
			redir_struct->type = IN;
	}
	else if (arg[char_i] == '>')
	{
		char_i++;
		if (arg[char_i] == '>')
			redir_struct->type = APPEND;
		else
			redir_struct->type = OUT;
	}
}

void	init_redirs(t_global *global, int cmd_i, int redirs)
{
	int	i;

	i = 0;
	while (i < redirs)
	{
		global->command[cmd_i].redir[i].file_name = NULL;
		global->command[cmd_i].redir[i].type = 0;
		i++;
	}
}