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
# include <sys/stat.h>
# include <signal.h>
# include "libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
//# include "pipex.h"

# define PROMPT "minishell>"

typedef struct s_token
{
	char			*history;
	char			type;
	struct s_token 	*next;
	struct s_token 	*prev;
}	t_token;

typedef struct s_enviro
{
	char			**nam_and_val;
	//struct s_enviro	*next;
}	t_enviro;

typedef struct s_global
{
	t_list		*enviro;
	char		*input;
}	t_global;

/* env_to_global.c */
bool	save_env_nam_and_val(char *envp, char **env_name, char **env_value);
bool	save_envp_to_list(t_list **list, char *envp);
bool	env_init(t_global *global, char **envp);
void	minishell_loop(t_global *global);


void		parsing(char *str, t_token parser);
void		isourcommand(t_token parser);
void		error_exit(t_global *parsing);
void		lexer(char *r_line);
char		**rebuild_env(t_enviro *enviro);
t_enviro	*ft_lstnew_env(char *content);


#endif
