#include "../minishell.h"

int	ft_echo(t_command *cmd)
{
	int		i;
	bool	newline;

	i = 1;
	newline = true;
	// we check if 2nd arg exists, and if it's "-n"
	if (cmd->arg[i] && !ft_strncmp(cmd->arg[i], "-n", 3))
	{
		newline = false;
		i++;
	}
	while (cmd->arg[i]) //we print further elements
	{
		printf("%s", cmd->args[i]);
		if (cmd->args[i + 1])
			printf(" "); //single space is correct
		i++;
	}
	if (newline)
		printf("\n");
	return (0);
}

