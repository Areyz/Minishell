/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:51:25 by mgalecki          #+#    #+#             */
/*   Updated: 2024/07/20 20:53:02 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("Usage: %s <pid> <string> \n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
	{
		send_sig(pid, *str);
		str++;
	}
	send_sig(pid, '\n');
	send_sig(pid, '\n');
	return (0);
}
