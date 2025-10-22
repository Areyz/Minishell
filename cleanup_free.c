/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:46:37 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/09/02 19:27:01 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Free all global's variables besides enviro */
void	free_global(t_global *global)
{
	if (global->enviro)
		ft_lstclear(&global->enviro, ft_clear_env);
}

void	free_all(t_global *global)
{
	if (global->input)
	{
		free(global->input);
		global->input = NULL;
	}
	if (global->command)
	{
		free_commands(global);
		global->command = NULL;
	}
	if (global->token_array)
	{
		free_string_array(global->token_array);
		global->token_array = NULL;
	}
}
