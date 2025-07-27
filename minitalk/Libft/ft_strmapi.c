/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:11:27 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/24 21:11:28 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	i = 0;
	result = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!(result))
		return (NULL);
	while (i < ft_strlen(s))
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/* 
//Function modfiy characters in string
char	ft_change_string(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

#include <stdio.h>
int main()
{
	char const *str = "AGSHA7821outy";
	char *result = ft_strmapi(str, ft_change_string);

	if (result)
	{
		printf("%s", result);
		free(result);
	}
	else
		printf("Allocation memory error");
	return (0);
}
*/