/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:32:55 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/28 20:32:00 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (nmemb > 2147483647 / size)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}
/* 
#include <stdio.h>

int main(void)
{
    size_t count = 5;
    size_t size = sizeof(int);
    int *arr = ft_calloc(count, size);
    if (arr)
    {
        for (size_t i = 0; i < count; i++)
            printf("%d ", arr[i]);
        printf("\n");
        free(arr);
    }
    else
    	printf("Allocation failed.\n");
	
	// size_t count2 = 5;
    // size_t size2 = sizeof(int);
    // int *arr2 = calloc(count2, size2);
    // if (arr2)
    // {
    //     for (size_t i2 = 0; i2 < count2; i2++)
    //         printf("%d ", arr2[i2]);
    //     printf("\n");
    //     free(arr2);
    // }
    // else
    // 	printf("Allocation failed.\n");
	
    return 0;
}
 */
