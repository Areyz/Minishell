/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:02:50 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/30 19:02:54 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_printf_chars(unsigned long n)
{
	char	a;
	int		len;

	len = 1;
	if (n >= 16)
	{
		len = len + ft_printf_chars(n / 16);
		ft_printf_chars(n % 16);
	}
	else
	{
		if (n < 10)
			a = n + '0';
		else
			a = (n - 10) + 'a';
		write (1, &a, 1);
	}
	return (len);
}

int	ft_printf_ptr(unsigned long ptr)
{
	unsigned long	n;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	n = (unsigned long)ptr;
	write(1, "0x", 2);
	return (2 + ft_printf_chars(n));
}
/* 
int main ()
{
	ft_printf_ptr(100);
	return (0);
}
*/