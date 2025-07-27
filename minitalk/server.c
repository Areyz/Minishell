/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:28:38 by mgalecki          #+#    #+#             */
/*   Updated: 2024/07/21 16:29:46 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_State	g_state = {0, 0};

void	sig_user1(int sig)
{
	(void)sig;
	g_state.c |= (1 << g_state.i);
	g_state.i++;
	if (g_state.i == 8)
	{
		write(1, &g_state.c, 1);
		g_state.c = 0;
		g_state.i = 0;
	}
}

void	sig_user2(int sig)
{
	(void)sig;
	g_state.i++;
	if (g_state.i == 8)
	{
		write(1, &g_state.c, 1);
		g_state.c = 0;
		g_state.i = 0;
	}
}

void	setup_signal_handlers(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;

	sa1.sa_handler = sig_user1;
	sigemptyset(&sa1.sa_mask);
	sa1.sa_flags = 0;
	sa2.sa_handler = sig_user2;
	sigemptyset(&sa2.sa_mask);
	sa2.sa_flags = 0;
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Your PID: %d\n", pid);
	setup_signal_handlers();
	while (1)
	{
	}
	return (0);
}
