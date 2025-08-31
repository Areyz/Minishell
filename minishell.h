/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:56:49 by mgalecki          #+#    #+#             */
/*   Updated: 2025/08/31 15:56:52 by mgalecki         ###   ########.fr       */
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

# define PROMPT "\033[22;33m$minishell> \033[0m"

enum e_chartype
{
	NONE,
	WORD,
	SPACE2,
	REDIR,
	QUOTE,
	DOLLAR,
	PIPE
};

typedef struct s_command
{
    char	*name;
	int		arg_num;
    char	**arg;
}   t_command;

typedef struct s_token
{
	// char			*history;
	// char			type;
	// struct s_token 	*next;
	// struct s_token 	*prev;
	char			*str;
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
}	t_enviro;

typedef struct s_global
{
	t_list		*enviro;
	char		*input;
	t_command	*command;
	char		**token_array;
	int			last_exit_code;
}	t_global;

/* env_to_global.c */
void	minishell_loop(t_global *global);

/* cleanup.c */
void	ft_clear_env(void *env_content_node);


// void		parsing(char *str, t_token parser);
// void		isourcommand(t_token parser);
// void		error_exit(t_global *parsing);
// void		lexer(char *r_line);
// char		**rebuild_env(t_enviro *enviro);
// t_enviro	*ft_lstnew_env(char *content);

/* tokenizer */
char	**tokenize(t_global *s);
void	init_token(t_token *t, char *source);

/*signals */
void	handle_sigint_heredoc(int sig);
void	sigquit_handler(int signo);
void	sigint_handler(int sig);
void	init_signal(void);

/*parse*/
int	process_and_execute(t_global *global);

/*validate input*/
int	get_and_validate_input(t_global *global);

// temp
void	free_ptr(void **ptr);
void	free_global(t_global *global);

/* build-in commands and env_utils */
void	ft_env(t_global *global);
int		ft_export(t_global *global, t_command *cmd);
int		ft_pwd(void);
void	ft_exit(t_global *global);
int		ft_unset(t_global *global, t_command *cmd);
int		ft_echo(t_command *cmd);
int		ft_cd(t_global *global, t_command *cmd);
void	save_env_nam_and_val(char *envp, char **env_name, char **env_value);
bool	save_envp_to_list(t_list **list, char *envp);
bool	env_init(t_global *global, char **envp);
void	env_update(t_global *global, const char *name, const char *value);

#endif
