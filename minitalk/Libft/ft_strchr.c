/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:23:38 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/16 21:23:50 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}
/* 
#include <string.h>
#include <stdio.h>
int	main()
{
	printf("%s\n", ft_strchr("asdsatda", '\0'));
	printf("%s\n", strchr("asdsatda", '\0'));
	return(0);
}
 */