#include "minishell.h"

void	launch_command(t_global *global)
{
	int	i;
	int	cmd_n;
	int	pipe_n;

	cmd_n = global->command_nbr;
	pipe_n = cmd_n - 1;
	signal(SIGINT, handle_sigint_heredoc);
	if (create_pipes(global, pipe_n))
		return ;
	i = 0;
	while (i < cmd_n)
	{
		global->pidz[i] = fork();
		if (global->pidz[i] < 0)
		{
			perror("minishell: fork");
			return ;
		}
		if (global->pidz[i] == 0)
			child_process(global, i, pipe_n);
		i++;
	}
	close_all_pipes(global, pipe_n);
	wait_for_children(global);
	signal(SIGINT, sigint_handler);
}