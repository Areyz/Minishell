/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:13:26 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/16 21:13:30 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
/* 
#include <stdio.h>
#include <ctype.h>
int	main()
{
	printf("%d\n", ft_tolower('Z'));
	printf("%d\n", tolower('Z'));
	return (0);
}
 */