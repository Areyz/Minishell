#include "../minishell.h"

int	ft_pwd(void)
{
	char	*cwd; //it won't work

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