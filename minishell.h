/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:55:19 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/30 20:38:24 by mgalecki         ###   ########.fr       */
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
# include <limits.h>
//# include "pipex.h"

# define PROMPT "minishell>"

typedef struct s_command
{
    char    *name;
	int		arg_num;
    char	**arg;
}   t_command;

typedef struct s_token
{
	char			*history;
	char			type;
	struct s_token 	*next;
	struct s_token 	*prev;
	char			*str:
	char			**array;
	int				maxw;
	int				maxc;
	int				word_i;
	int				letter_i;
	enum e_chartype	mode;
	enum e_chartype	modemem;
	char			quote;
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
	t_command	*command;
	char		*token_array[];
}	t_global;

/* env_to_global.c */
void	save_env_nam_and_val(char *envp, char **env_name, char **env_value);
bool	save_envp_to_list(t_list **list, char *envp);
bool	env_init(t_global *global, char **envp);
void	minishell_loop(t_global *global);

/* cleanup.c */
void	ft_clear_env(void *env_content_node);

/* exit.c */
void	ft_exit(t_global *global);//, int exit_status);

void		parsing(char *str, t_token parser);
void		isourcommand(t_token parser);
void		error_exit(t_global *parsing);
void		lexer(char *r_line);
char		**rebuild_env(t_enviro *enviro);
t_enviro	*ft_lstnew_env(char *content);


/*signals */
void	handle_sigint_heredoc(int sig);
void	sigquit_handler(int signo);
void	sigint_handler(int sig);
void	init_signalz(void);

/*parse*/
static int	process_and_execute(t_global *global);

/*validate input*/
static int	get_and_validate_input(t_global *global);

// temp
void	free_ptr(void **ptr);
void	free_global(t_global *global);

/* build-in commands */
void	ft_env(t_global *global);
void	ft_export(t_global *global, t_token *token);
int     ft_pwd(void);
void    ft_exit(t_global *global);

#endif
