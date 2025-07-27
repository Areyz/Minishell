/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 13:25:28 by mgolasze          #+#    #+#             */
/*   Updated: 2024/12/25 15:29:45 by mgolasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ch1;
	unsigned char	*ch2;

	if (n == 0)
		return (0);
	ch1 = (unsigned char *) s1;
	ch2 = (unsigned char *) s2;
	while ((*ch1 == *ch2) && n - 1 > 0)
	{
		ch1++;
		ch2++;
		n--;
	}
	return ((int)(*ch1 - *ch2));
}
