/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:00:53 by mgolasze          #+#    #+#             */
/*   Updated: 2025/07/30 20:00:57 by mgolasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Error chandling and freeing memory
void error_exit(s_struct *parsing)
{
	if(parsing)
	free(parsing);
	perror = 
}