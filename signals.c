/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:43:20 by mgalecki          #+#    #+#             */
/*   Updated: 2025/08/30 17:33:11 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
A signal handler (automatically called when the process 
receives a signal like SIGINT -> Ctrl+C). 
The argument sig is the signal number (e.g. 2 for SIGINT).
*/
void	handle_sigint_heredoc(int sig)
{
	(void)sig;
	write(1, "\n", 1);
}
/*
This is a handler for SIGQUIT (Ctrl+\).
Effect: pressing Ctrl+\ does nothing in the shell.
*/

void	sigquit_handler(int signo)
{
	(void)signo;
}

/*
After pressinh Ctrl+C at the prompt, unfinished command is cleared 
and we see a fresh prompt on the next line.
*/
void	sigint_handler(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

/*
Declares a sigaction structure for configuring signal behavior.
*/
void	init_signalz(void)
{
	struct sigaction	sa;

	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGQUIT, &sa, NULL);
	sigaction(SIGTSTP, &sa, NULL);
	sa.sa_handler = sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
}