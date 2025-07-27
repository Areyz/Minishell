/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:00:54 by mgalecki          #+#    #+#             */
/*   Updated: 2024/04/20 20:01:00 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_print_nbr_help(int n);

int	ft_printf_nbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write (1, "-2", 2);
		n = 147483648;
		len = len + 2;
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = n * -1;
		len++;
	}
	len = len + ft_print_nbr_help(n);
	return (len);
}

static int	ft_print_nbr_help(int n)
{
	char	a;
	int		len;

	len = 0;
	if (n >= 10)
	{
		len = len + ft_printf_nbr(n / 10);
		ft_printf_nbr(n % 10);
		len++;
	}
	else
	{
		a = n + '0';
		write(1, &a, 1);
		len++;
	}
	return (len);
}
/* 
int	main ()
{
	ft_printf_nbr(-203012);
	return (0);
}
*/