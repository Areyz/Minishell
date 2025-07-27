/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:05:41 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/16 16:05:52 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	dl;
	size_t	sl;

	sl = ft_strlen(src);
	if (!dst && size == 0)
		return (sl);
	d = ft_strlen(dst);
	dl = d;
	if (size <= dl)
		return (size + sl);
	s = 0;
	while (src[s] && d + 1 < size)
	{
		dst[d] = src[s];
		d++;
		s++;
	}
	dst[d] = '\0';
	return (dl + sl);
}
/* 
#include <stdio.h>
#include <bsd/string.h>

int	main()
{
	const char	*src1 = "qwerty";
	char	dest1[20];
	size_t	result;
	size_t	size1;

	size1 = 20;
	result = ft_strlcat(dest1, src1, size1);
	printf("%zu\n", result);


	const char	*src2 = "qwerty";
	char	dest2[20];
	size_t	result2;
	size_t	size2;

	size2 = 20;
	result2 = strlcat(dest2, src2, size2);
	printf("%zu\n", result2);

	return (0);
}
 */