#include "minishell.h"

int	is_space(int z)
{
	if (z == 32 || (z > 8 && z < 14))
		return (1);
	else
		return (0); 
}

bool	user_input_is_space(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		if(!is_space(str[i]))
			return(false);
		c++;
	}
	return(true);
}
