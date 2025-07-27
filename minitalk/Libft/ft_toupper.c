/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:43:10 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/16 20:43:14 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/* 
#include <stdio.h>
#include <ctype.h>
int	main()
{
	printf("%d\n", ft_toupper('w'));
	printf("%d\n", toupper('w'));
	return (0);
}
 */