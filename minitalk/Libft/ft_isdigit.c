/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:12:30 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/14 21:12:35 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int main ()
{
	printf("%d\n",ft_isdigit(':'));
	printf("%d",isdigit(':'));
	return (0);
}
 */
