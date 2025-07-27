/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:47:25 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/17 17:47:27 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n--)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*  
#include <stdio.h>
#include <string.h> 
int	main()
{
	char	src1[] = "\0";
	size_t size1 = 15;
	char	dest1[] = "asddvvc";
	printf("%d\n", ft_memcmp(dest1, src1, size1));

	char	src2[] = "\0";
	size_t size2 = 15;
	char	dest2[] = "asddvvc";
	printf("%d\n", memcmp(dest2, src2, size2));
	return (0);
}
 */