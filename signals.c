/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:43:20 by mgalecki          #+#    #+#             */
/*   Updated: 2025/08/16 18:47:27 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Function handle usage Ctr + C during writing comand mode. 
Function cleaning the line and showing new empty promt.
rl_on_new_line - delete what user wrote
rl_redisplay - create new promt
*/
void	signal_reset_line(int signo)
{
	(void)signo;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

/*
Function set minishell behavior, when he is waiting for entering the command
ignore sigquit - ignore Ctrl + \
*/
void	set_signals_interactive(void)
{
	struct sigaction	act;

	ignore_sigquit();
	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_reset_prompt;
	sigaction(SIGINT, &act, NULL);
}

/*
Function will be using when minishell not waiting for the command, but when he executing command
Function display new line. It is not reset prompt.
*/
void	signal_print_newline (int signo)
{
	(void)signal;
	write(1, "\n", 1);
	rl_on_new_line();
}

/*
Function will execute when minishell will start for example comands cat, ls and he should not react for Ctrl+C
*/
void	set_signals_noninteractive(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	sigaction(SIGQUIT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}
/*
It set that minishell will ignore Ctrl+\ (SIGQUIT)
SIG_IGN is special function to ignore signal
*/
void	ignore_sigquit(void)
{
	struct sigaction	act;
	
	act.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &act, NULL);
}