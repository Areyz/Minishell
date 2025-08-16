/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:55:19 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/15 22:37:08 by mgalecki         ###   ########.fr       */
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
	t_enviro	*enviro;
}	t_global;

void		parsing(char *str, t_token parser);
void		isourcommand(t_token parser);
void		error_exit(t_global *parsing);
void		lexer(char *r_line);
char		**rebuild_env(t_enviro *enviro);
t_enviro	*ft_lstnew_env(char *content);
t_enviro	*env_init(char **envp);

//signals
void	signal_reset_line(int signo);
void	set_signals_interactive(void);
void	signal_print_newline (int signo);
void	set_signals_noninteractive(void);
void	ignore_sigquit(void);


#endif
