/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:59:51 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/14 20:59:57 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/* 
#include <string.h>
#include <stdio.h>
int	main()
{
	printf("%ld\n", ft_strlen("ldjsjajsjs;jsad;"));
	printf("%ld", strlen("ldjsjajsjs;jsad;"));
	return (0);
}
 */
