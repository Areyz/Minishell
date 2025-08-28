/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:55:19 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/18 22:02:17 by mgalecki         ###   ########.fr       */
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
void	signal_reset_line(int signo);
void	set_signals_interactive(void);
void	signal_print_newline (int signo);
void	set_signals_noninteractive(void);
void	ignore_sigquit(void);

/*parse*/
bool	parse_input(t_global *global);
int		is_space(int z);
bool	user_input_is_space(char *str);

// temp
void	free_ptr(void **ptr);
void	free_global(t_global *global);

/* build-in commands */
void	ft_env(t_global *global);
void	ft_export(t_global *global, t_token *token);
int     ft_pwd(void);
void    ft_exit(t_global *global);

#endif
