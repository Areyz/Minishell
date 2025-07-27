/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:53:38 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/24 21:53:40 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
void	ft_modify_string(unsigned int i, char *c)
{
	if (i < 5 && *c >= '0' && *c <= '9')
		*c = *c + 1;
}

#include <stdio.h>

int main ()
{
	char	str[] = "6712sjabsh231";
	printf("Before modification: %s\n", str);
	ft_striteri(str, ft_modify_string);
	printf("After modification: %s\n", str);
	return (0);
}
*/