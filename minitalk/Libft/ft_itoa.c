/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:27:39 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/22 21:27:44 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_get_digits(int n)
{
	size_t	i;

	i = 1;
	while (n)
	{
		n = n / 10;
		if (n)
			i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*result;
	size_t		digits;
	long int	number;

	number = n;
	digits = ft_get_digits(n);
	if (n < 0)
	{
		number = number * (-1);
		digits++;
	}
	result = (char *)malloc(sizeof(char) * (digits + 1));
	if (!result)
		return (NULL);
	*(result + digits) = '\0';
	while (digits--)
	{
		*(result + digits) = number % 10 + '0';
		number = number / 10;
	}
	if (n < 0)
		*(result + 0) = '-';
	return (result);
}
/* 
#include <stdio.h>
int	main ()
{
	int	num1 = -767890320;
	char *result = ft_itoa(num1);

	if (result)
	{
		printf("%s\n", result);
		//printf("odst\n");
		free(result);
	}
	else
		printf("Memory allocation error");
	return (0);
}
*/