/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:01:24 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/14 21:01:30 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = 0;
}
/*
#include <strings.h>
#include <stdio.h>
int	main()
{
	char buffer[10] = "aaaaaaaaaa";
	ft_bzero(buffer, 3);
	printf("%s\n", buffer);

	char buffer1[10] = "aaaaaaaaaa";
	bzero(buffer1, 3);
	printf("%s\n", buffer1);

	return(0);
}
*/
