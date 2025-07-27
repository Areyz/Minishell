/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:09:16 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/14 21:09:24 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (16384);
	return (0);
}
/* 
#include <ctype.h>
#include <stdio.h>
int	main()
{
    printf("%d\n", ft_isprint(128));
    printf("%d", isprint(128));
    return (0);
}
 */
