/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:04:46 by mgolasze          #+#    #+#             */
/*   Updated: 2025/06/28 20:00:57 by mgolasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <string.h>
# include <libft.h>
# include <errno.h>

void	input_process(char *infile, char *cmd1, int *pipe_fd, char **env);
void	output_process(char *outfile, char *cmd2, int *pipe_fd, char **env);
pid_t	launch_input(char *infile, char *cmd1, int *pipe_fd, char **envp);
pid_t	launch_output(char *outfile, char *cmd2, int *pipe_fd, char **envp);
int		main(int argc, char *argv[], char *envp[]);
void	error_exit(int code, char *message);
char	*create_path(char *dir, char *cmd);
char	*find_path_env(char **env);
char	*find_command(char *cmd, char **env);
void	free_split(char **split);
void	error_fileperm(char *file);
void	handle_exec(char *cmd, char **env);

# define READ_END 0
# define WRITE_END 1

#endif
