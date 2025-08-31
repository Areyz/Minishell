/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:13:01 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/08/28 15:13:02 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_echo(t_command *cmd)
{
	int		i;
	bool	newline;

	i = 1;
	newline = true;
	// we check if 2nd arg exists, and if it's "-n"
	if (cmd->arg[i] && !ft_strncmp(cmd->arg[i], "-n", 3))
	{
		newline = false;
		i++;
	}
	while (cmd->arg[i]) //we print further elements
	{
		printf("%s", cmd->arg[i]);
		if (cmd->arg[i + 1])
			printf(" "); //single space is correct
		i++;
	}
	if (newline)
		printf("\n");
	return (0);
}

