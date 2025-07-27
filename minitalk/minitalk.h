/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:50:20 by mgalecki          #+#    #+#             */
/*   Updated: 2024/07/20 20:51:07 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include "Libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct State
{
	int	c;
	int	i;
}		t_State;

void	send_sig(pid_t pid, char c);
void	sig_user1(int sig);
void	sig_user2(int sig);

#endif