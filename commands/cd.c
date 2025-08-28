#include "../minishell.h"

static void	pwd_update(t_global *global, const char *old_dir)
{
	//this makes no sense !
	char	new_dir[4096];

	env_update(global, "OLDPWD", old_dir);
	if (getcwd(new_dir, sizeof(new_dir)) != NULL)
		env_update(global, "PWD", new_dir);
	else
		perror("cd: getcwd error after chdir");
}

int	ft_cd(t_global *global, t_command *cmd) // to be tested
{
	char	*path;
	char	current_dir[4096];	//it's the max size of path in linux

	if (!getcwd(current_dir, sizeof(current_dir)))
	{
		perror("cd: getcwd error");
		return (1);
	}
	if (!cmd->arg[1])
	{
		write(2, "cd: path required\n", 18);
		// 2 == stderr
		return (1);
	}
	path = cmd->arg[1];
	if (chdir(path) != 0)
	{
		perror("cd");
		return (1);
	}
	update_pwd_variables(global, current_dir);
	return (0);
}