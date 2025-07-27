/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:07:19 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/14 21:07:23 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (8);
	return (0);
}
/* 
#include <ctype.h>
#include <stdio.h>
int	main()
{
    printf("%d\n", ft_isalnum('@'));
    printf("%d", isalnum('@'));
    return (0);
}
 */
