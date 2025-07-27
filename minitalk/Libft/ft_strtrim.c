/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:08:27 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/19 20:08:28 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	checkifset(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	while (*s1)
	{
		if (checkifset(((char)*s1), set) == 1)
			s1++;
		else
			break ;
	}
	size = ft_strlen(s1);
	while (size != 0)
	{
		if (checkifset(s1[size - 1], set) == 1)
			size--;
		else
			break ;
	}
	str = (char *)malloc(size * sizeof(char) + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)s1, size +1);
	return (str);
}
/* 
#include <stdio.h>
int main()
{
	char *s = "asd";
	char *st = "d";
	char *result = ft_strtrim(s, st);
	if (result)
	{
		printf("%s", result);
		free(result);
	}
	else
		printf("Memory allocation error");
	return (0);
	 
}
 */