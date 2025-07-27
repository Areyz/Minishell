/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:06:13 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/15 22:08:15 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i + 1 < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = 0;
	while (src[i])
		i++;
	return (i);
}
/* 
#include <stdio.h>
#include <bsd/string.h>

int	main()
{
	const char	*src1 = "qwerty";
	char	dest1[20];
	size_t	result;
	result = ft_strlcpy(dest1, src1, sizeof(dest1));
	printf("%zu\n", result);

	const char	*src2 = "qwerty";
	char	dest2[20];
	size_t	result2;
	result2 = strlcpy(dest2, src2, sizeof(dest2));
	printf("%zu\n", result2);
	return (0);
}
 */