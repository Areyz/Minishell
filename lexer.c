/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:55:29 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/11 17:23:24 by mgolasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//basic lexer for tokenising and categorising
char	lexer(char **argv)
{
	int			i;
	t_token		next;
	t_token		new;

	ft_lstadd_back

	i = 1;
	while (argv[i])
	//todo - linked list with next and prev
	{
		parsing(argv[i]);
		i++;
	}
}
