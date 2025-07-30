/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:55:19 by mgolasze          #+#    #+#             */
/*   Updated: 2025/07/30 21:08:31 by mgolasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <signal.h>
# include "libft.h"
# include "pipex.h"

typedef struct s_token
{
	char	*history;
	char	type;
	s_token *next;
	s_token *prev;
}	t_token;

void	parsing(char *str, t_token parser);
void	isourcommand(t_token parser);
void	error_exit(s_struct *parsing);
char	lexer(char **argv);

#endif
