/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:26:27 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/17 12:26:31 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char const	*result;

	result = NULL;
	while (*s)
	{
		if (*s == (char)c)
			result = s;
		s++;
	}
	if (*s == (char)c)
		result = s;
	return ((char *)result);
}
/* 
#include <string.h>
#include <stdio.h>
int	main()
{
	printf("%s\n", ft_strrchr("asdsatda", 't'));
	printf("%s\n", strrchr("asdsatda", 't'));
	return(0);
}
*/