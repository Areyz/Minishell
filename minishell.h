/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:33:09 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/09/01 19:46:04 by mgalecki         ###   ########.fr       */
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

typedef enum e_redir_type
{
	IN,
	OUT,
	APPEND,
	HEREDOC,
	INVALID
}	t_redir_type;

typedef struct s_redir
{
	t_redir_type	type;
	char			*file_name;
}	t_redir;

typedef struct s_command
{
    char	*name;
	int		arg_num;
    char	**arg;
	int		redir_count;
	t_redir	*redir;
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
	int			comand_nbr;
	char		**token_array;
	int			last_exit_code;
}	t_global;

/* env_to_global.c */
void	minishell_loop(t_global *global);

/* free & */
void	ft_clear_env(void *env_content_node);
void	free_string_array(char **arg);
void	safefree(void *ptr);
void	ft_clear_env_list(t_list *node);
void	ft_clear_env(void *env_node);
void	free_commands(t_global *global);
void	free_all(t_global *global);

/* tokenizer.c */
char	**tokenize(t_global *s);
void	process_char(t_token *t, t_global *s);
void	char_check(t_token *t);
void	quote_check(t_token *t);
void	init_token(t_token *t, char *source);
char	**str_array_realloc(char **old, size_t add_slots);

/* tokenizer2.c */
void	dolarskan(t_token *t, t_global *s);
void	question_mark(t_token *t, t_global *s);
void	next_word(t_token *t);
void	put_letter(t_token *t);

/*signals */
void	handle_sigint_heredoc(int sig);
void	sigquit_handler(int signo);
void	sigint_handler(int sig);
void	init_signal(void);

/*parse*/
int		process_and_execute(t_global *global);

/*lexer*/
void	lexer (t_global	*global);
void	*safe_malloc(size_t size);
void	alloc_commands(t_global *global);
void	init_commands(t_global *global);
void init_iterators(int *tkn_i, int *arg_i, int *cmd_i);
void	hanlde_pipe_token(t_global *global, int *cmd_i, int *arg_i, int *tkn_i);


/*validate input*/
int		get_and_validate_input(t_global *global);

/* pipes */
int		create_pipes(t_global *global, int pipe_n);
void	close_pipes(t_shell *shell, int pipe_n);

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
void	ft_quit(t_shell *shell, int exit_code);
int		ft_builtins(t_global *global, int cmd_n);
char	**env_array_from_enviro(t_global *global);
int		validate_pipe_syntax(t_global *global);
int		check_initial_pipe(t_global *global);

/* exec */
void	launch_command(t_global *global);
void	redir_control(t_global *global, int i);
void	handle_redirections(t_global *global, int i, int pipe_n);
char	*find_path(t_global *global, int i);
char	*find_sub_path(t_global *global, int i);
char	*multicat(char	**input);
char	*next_folder(t_global *global, int *offset);
char	*find_env_val(char *var, t_list *env_list, unsigned int limit);

#endif
