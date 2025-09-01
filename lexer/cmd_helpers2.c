/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_helpers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:36:13 by mgalecki          #+#    #+#             */
/*   Updated: 2025/09/01 21:18:04 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fill_args_helper(t_global *global, int i, int k, int *h)
{
	global->command[k].arg[*h]
		= safe_malloc(ft_strlen(global->token_array[i]) + 1);
	ft_strlcpy(global->command[k].arg[*h], global->token_array[i],
		ft_strlen(global->token_array[i]) + 1);
	(*h)++;
}

void	fill_args(t_global *global)
{
	int	i;
	int	k;
	int	h;

	init_iterators(&i, &h, &k);
	while (global->token_array[i])
	{
		if (ft_strncmp(global->token_array[i], "|", 1) == 0)
		{
			global->command[k].arg[h] = NULL;
			k++;
			h = 0;
			i++;
			continue ;
		}
		fill_args_helper(global, i, k, &h);
		if (global->token_array[i + 1] == NULL)
		{
			global->command[k].arg[h] = NULL;
			break ;
		}
		i++;
	}
}

void	init_iterators(int *tkn_i, int *arg_i, int *cmd_i)
{
	*tkn_i = 0;
	*arg_i = 0;
	*cmd_i = 0;
}