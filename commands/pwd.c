#include "../minishell.h"

int	ft_pwd(void) //it works
{
	char	cwd[4096]; //it's the max size of path in linux

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
		return (0);
	}
	else
	{
		perror("pwd error");
		return (1);
	}
}