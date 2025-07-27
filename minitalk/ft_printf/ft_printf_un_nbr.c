/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_un_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:28:46 by mgalecki          #+#    #+#             */
/*   Updated: 2024/04/20 21:28:52 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_un_nbr(unsigned int n)
{
	char	a;
	int		len;

	len = 1;
	if (n >= 10)
	{
		len = len + ft_printf_un_nbr(n / 10);
		ft_printf_un_nbr(n % 10);
	}
	else
	{
		a = n + '0';
		write(1, &a, 1);
	}
	return (len);
}
/* 
int main ()
{
	ft_printf_un_nbr(82913789);
	return (0);
}
*/