/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:48:33 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/30 18:48:39 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf_char(int c);
int	ft_printf_str(char *str);
int	ft_printf_ptr(unsigned long ptr);
int	ft_printf_nbr(int n);
int	ft_printf_un_nbr(unsigned int n);
int	ft_printf_hex_low(unsigned int n);
int	ft_printf_hex_upp(unsigned int n);
int	ft_printf(const char *s, ...);

#endif