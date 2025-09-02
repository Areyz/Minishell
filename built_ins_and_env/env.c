/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:13:44 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/09/02 19:14:29 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_env(t_global *global)
{
	t_list		*env;
	t_enviro	*data;

	env = global->enviro;
	while (env)
	{
		data = (t_enviro *)env->content;
		printf("%s=%s\n", data->nam_and_val[0], data->nam_and_val[1]);
		env = env->next;
	}
	return (0);
}
