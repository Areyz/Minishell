/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:05:37 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/14 21:05:44 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*s;
	char		*d;

	i = 0;
	s = (char *)src;
	d = (char *)dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/* 
#include <stdio.h>
#include <string.h>
int	main ()
{
	char *src1 = "aqwerdsa";
	char dest1[10];
	ft_memcpy(dest1,src1, 3);
	printf("%s\n", dest1);

	char *src2 = "aqwerdsa";
	char dest2[10];
	memcpy(dest2,src2, 3);
	printf("%s\n", dest2);
	return(0);
}
 */
