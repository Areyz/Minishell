/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:55:19 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/09 22:50:34 by mgolasze         ###   ########.fr       */
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
//# include "pipex.h"

typedef struct s_token
{
	char			*history;
	char			type;
	struct s_token 	*next;
	struct s_token 	*prev;
}	t_token;

typedef struct s_enviro
{
	char			*content;
	struct s_enviro	*next;
}	t_enviro;

typedef struct s_global
{
	t_enviro	*enviro;
}	t_global;

void		parsing(char *str, t_token parser);
void		isourcommand(t_token parser);
void		error_exit(t_global *parsing);
char		lexer(char **argv);
char		**rebuild_env(t_enviro *enviro);
t_enviro	*ft_lstnew_env(char *content);
t_enviro	*env_init(char *envp[]);

#endif
