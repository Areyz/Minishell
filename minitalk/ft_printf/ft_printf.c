/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:47:03 by mgalecki          #+#    #+#             */
/*   Updated: 2024/04/20 22:47:04 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_what_format(char c, va_list arg)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = len + ft_printf_char(va_arg(arg, int));
	else if (c == 's')
		len = len + ft_printf_str(va_arg(arg, char *));
	else if (c == 'p')
		len = len + ft_printf_ptr((unsigned long)va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		len = len + ft_printf_nbr(va_arg(arg, int));
	else if (c == 'u')
		len = len + ft_printf_un_nbr(va_arg(arg, unsigned int));
	else if (c == 'x')
		len = len + ft_printf_hex_low(va_arg(arg, unsigned int));
	else if (c == 'X')
		len = len + ft_printf_hex_upp(va_arg(arg, unsigned int));
	else if (c == '%')
	{
		write(1, "%", 1);
		len = len + 1;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		len;

	va_start(arg, s);
	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			len = len + ft_what_format(*s, arg);
			s++;
		}
		else
		{
			write(1, s, 1);
			len = len + 1;
			s++;
		}
	}
	va_end(arg);
	return (len);
}
/* 
int main ()
{
	ft_printf("%s, %d, %i\n", "asdasda", 11, -6);
	ft_printf("%s, %d, %i\n", "rwererwe", 15, -19);
	ft_printf("%s, %d, %i\n", "dfgdfgf", 16, -10);
	ft_printf("%s, %d, %i\n", "afgfg", 17, -11);
	ft_printf("%s, %d, %i\n", "asddfgdfgda", 18, -17);
	ft_printf("%s, %d, %i\n", "asdaszxcda", 19, -18);
	ft_printf("%s, %d, %i\n", "asdsdf", 10, -176);
	ft_printf("%s, %d, %i\n", "asdasdsdfsda", 16, -1643);
	ft_printf("%s, %d, %i\n", "asdazxcsda", 19, -1436);
	ft_printf("%s, %d, %i\n", "asdassadsdda", 18, -1345);
	return (0);
}
*/