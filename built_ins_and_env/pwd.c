/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:14:24 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/09/02 19:17:07 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd != NULL)
	{
		printf("%s\n", cwd);
		free(cwd);
		return (0);
	}
	else
	{
		perror("pwd error");
		return (1);
	}
}
