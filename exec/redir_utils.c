/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:47:52 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/09/02 19:18:35 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	heredoc_loop(int fd, char *terminator)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strncmp(line, terminator, ft_strlen(line)) == 0)
		{
			if (!line)
				perror("minishell: here-document delimited by end-of-file\n");
			free(line);
			break ;
		}
		if (write(fd, line, ft_strlen(line)) == -1 || write(fd, "\n", 1) == -1)
		{
			perror("minishell: write");
			free(line);
			return (-1);
		}
		free(line);
	}
	return (0);
}

static int	heredoc(char *terminator)
{
	const char	*tmp_path = "/tmp/heredoc_temp";
	int			fd;

	fd = open(tmp_path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("minishell: open");
		return (-1);
	}
	if (heredoc_loop(fd, terminator) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	fd = open(tmp_path, O_RDONLY);
	if (fd == -1)
	{
		perror("minishell: open");
		return (-1);
	}
	unlink(tmp_path);
	return (fd);
}

static void	in_redirs(t_global *global, int i, int j)
{
	int		helper_fd;

	if (global->command[i].redir[j].type == IN)
	{
		helper_fd = open(global->command[i].redir[j].file_name, O_RDONLY);
		if (helper_fd == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			perror(global->command[i].redir[j].file_name);
			exit(1);
		}
		global->pipe_fd[i][0] = open(global->command[i].redir[j].file_name,
				O_RDONLY);
		dup2(global -> pipe_fd[i][0], STDIN_FILENO);
	}
	else if (global->command[i].redir[j].type == HEREDOC)
	{
		global->pipe_fd[i][0] = heredoc(global->command[i].redir[j].file_name);
		dup2(global->pipe_fd[i][0], STDIN_FILENO);
	}
}

static void	out_redirs(t_global *global, int i, int j)
{
	if (global->command[i].redir[j].type == OUT)
	{
		global->pipe_fd[i][1] = open(global->command[i].redir[j].file_name,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(global->pipe_fd[i][1], STDOUT_FILENO);
	}
	else if (global->command[i].redir[j].type == APPEND)
	{
		global->pipe_fd[i][1] = open(global->command[i].redir[j].file_name,
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		dup2(global->pipe_fd[i][1], STDOUT_FILENO);
	}
}

void	redir_control(t_global *global, int i)
{
	int		j;

	j = 0;
	while (j < global->command[i].redir_count)
	{
		if (global->command[i].redir[j].type == INVALID)
		{
			ft_putstr_fd("minishell: empty redir", 2);
			exit(1);
		}
		in_redirs(global, i, j);
		out_redirs(global, i, j);
		j++;
	}
}
