/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:38:08 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/17 18:38:12 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	if (*little == 0)
		return ((char *)big);
	b = 0;
	l = 0;
	while (big[b] && b < len)
	{
		while (big[b + l] == little[l] && big[b + l] && b + l < len)
		{
			l++;
			if (little[l] == 0)
				return ((char *)big + b);
		}
		b++;
		l = 0;
	}
	return (0);
}
/* 
#include <stdio.h>
#include <bsd/string.h>

int	main()
{	
	const char 	*str1 = "qwertyu";
	const char 	*str2 = "ty";
	char *result1 = ft_strnstr(str1, str2, 7);
	printf("%s\n", result1);

	const char 	*str3 = "qwertyu";
	const char 	*str4 = "ty";
	char *result2 = strnstr(str3, str4, 7);
	printf("%s\n", result2);
	return(0);
}
*/