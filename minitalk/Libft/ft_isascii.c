/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:47:05 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/14 20:56:11 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= '\0' && c <= 127)
		return (1);
	return (0);
}
/* 
#include <ctype.h>
#include <stdio.h>
int	main ()
{
    printf("%d\n", ft_isascii(128));
    printf("%d", isascii(128));
    return (0);
}
 */
