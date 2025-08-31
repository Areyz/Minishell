/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:14:24 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/08/28 15:14:26 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int	ft_pwd(void) //it works, but for now I implemented in dynamical way
// {
// 	// char	cwd[4096]; //it's the max size of path in linux
// 	char	cwd[PATH_MAX]; 

// 	if (getcwd(cwd, sizeof(cwd)) != NULL)
// 	{
// 		printf("%s\n", cwd);
// 		return (0);
// 	}
// 	else
// 	{
// 		perror("pwd error");
// 		return (1);
// 	}
// }

// alternaive way - to be tested
int ft_pwd(void)
{
	char *cwd;

	cwd = getcwd(NULL, 0); // let getcwd malloc the buffer
	if (cwd != NULL)
	{
		printf("%s\n", cwd);
		free(cwd); // don't forget to free!
		return 0;
	}
	else
	{
		perror("pwd error");
		return 1;
	}
}
