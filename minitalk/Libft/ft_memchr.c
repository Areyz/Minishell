/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:04:05 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/17 16:04:08 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cc;
	size_t			i;

	str = (unsigned char *)s;
	cc = (unsigned char)c;
	i = 0;
	while (n > 0)
	{
		if (str[i] == cc)
			return ((void *)&str[i]);
		i++;
		n--;
	}
	return (0);
}
/*  
#include <stdio.h>
#include <string.h> 
int	main()
{
	char	src1[] = "abcdefg";
	size_t size1 = 3;
	char	d1 = 'z';
	void *result1 = ft_memchr(src1, d1, size1); 
	printf("%s\n", (char *)result1);

	char	src2[] = "abcdefg";
	size_t size2 = 3;
	char	d2 = 'z';
	void *result2 = memchr(src2, d2, size2); 
	printf("%s\n", (char *)result2);
	return (0);
}
 */