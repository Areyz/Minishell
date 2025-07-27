/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:29:54 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/18 22:25:51 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(s) + 1;
	ptr = (char *)malloc(size * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, size);
	return (ptr);
}
/* 
#include <stdio.h>
#include <string.h>
int main()
{
    const char *original = "0";
    char *duplicate = ft_strdup(original);

    if (duplicate)
        printf("Original: %s\nDuplicate: %s\n", original, duplicate);
    else
        printf("Error of the memory allocation\n");
    free(duplicate);


	const char *original1 = "0";
    char *duplicate1 = strdup(original1);

    if (duplicate1)
        printf("Original: %s\nDuplicate: %s\n", original1, duplicate1);
    else
        printf("Error of the memory allocation\n");
    free(duplicate1);

    return 0;
}
*/
