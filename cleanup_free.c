/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:46:37 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/09/01 19:47:19 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Free all global's variables besides enviro */
void	free_global(t_global *global)
{
	// if (global)
	// 	free_global(global);
	if (global->enviro)
		ft_lstclear(&global->enviro, ft_clear_env);
}
