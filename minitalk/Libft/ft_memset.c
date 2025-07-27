/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:08:16 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/14 21:08:20 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	cc;
	char			*ptr;

	ptr = s;
	cc = c;
	while (n > 0)
	{
		*ptr = cc;
		ptr++;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>
int main ()
{
	char buffer [10] = "kkkkkkkkkk";
	ft_memset(buffer,'t', 3);
	printf("%s\n", buffer);
	
	char buffer1 [10] = "kkkkkkkkkk";
	memset(buffer1,'t', 3);
	printf("%s", buffer1);
	return (0);
}
*/
