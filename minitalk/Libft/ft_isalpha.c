/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:11:34 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/14 21:11:37 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1024);
	return (0);
}
/* 
#include <ctype.h>
#include <stdio.h>
int main ()
{
    printf("%d\n", ft_isalpha(123));
    printf("%d", isalpha(12));
    return (0);
}
 */
