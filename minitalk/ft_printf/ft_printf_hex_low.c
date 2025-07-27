/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_low.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:22:15 by mgalecki          #+#    #+#             */
/*   Updated: 2024/04/20 22:22:16 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_hex_low(unsigned int n)
{
	char	a;
	int		len;

	len = 1;
	if (n >= 16)
	{
		len = len + ft_printf_hex_low(n / 16);
		ft_printf_hex_low(n % 16);
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
/* 
int	main ()
{
	ft_printf_hex_low(31233);
	return (0);
}
*/