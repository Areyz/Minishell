/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:45:59 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/09/01 19:46:00 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_initial_pipe(t_global *global)
{
	if (global->token_array[0] && ft_strncmp(global->token_array[0], "|", 1) == 0)
	{
		printf("minishell: syntax error near unexpected token '|'\n");
		return (1);
	}
	return (0);
}

int	validate_pipe_syntax(t_global *global)
{
	int	i;

	i = 0;
	if (check_initial_pipe(global))
		return (1);
	while (global->token_array[i])
	{
		if (ft_strncmp(global->token_array[i], "|", 1) == 0)
		{
			if (global->token_array[i + 1] == NULL)
			{
				printf("minishell: syntax error near unexpected token '|'\n");
				return (1);
			}
			if (global->token_array[i + 1]
				&& ft_strncmp(global->token_array[i + 1], "|", 1) == 0)
			{
				printf("minishell: syntax error near unexpected token '|'\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}