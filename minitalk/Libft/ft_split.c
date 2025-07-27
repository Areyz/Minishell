/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:20:17 by mgalecki          #+#    #+#             */
/*   Updated: 2024/03/20 20:20:19 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_set_vars(size_t *i, int *j, int *word_s);
static int	ft_word_count(const char *str, char c);
static char	*ft_make_word(const char *str, int start, int end);
static void	*ft_free(char **strs, int count);

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_s;
	size_t	i;
	int		j;

	ft_set_vars(&i, &j, &word_s);
	result = ft_calloc((ft_word_count(s, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && word_s < 0)
			word_s = i;
		else if ((s[i] == c || i == ft_strlen(s)) && word_s >= 0)
		{
			result[j] = ft_make_word(s, word_s, i);
			if (!(result[j]))
				return (ft_free(result, j));
			word_s = -1;
			j++;
		}
		i++;
	}
	return (result);
}

static void	ft_set_vars(size_t *i, int *j, int *word_s)
{
	*i = 0;
	*j = 0;
	*word_s = -1;
}

static int	ft_word_count(const char *str, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (count);
}

static char	*ft_make_word(const char *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}
/* 
#include <stdio.h>
int main ()
{
	char *s = "checkRRRthisRfunctionR:)RRR";
	char **result = ft_split(s, 'R');
	if (result)
	{
		
		for (int i = 0; result[i]; i++)
		{
			printf("Word %d: %s\n", i + 1, result[i]);
			free (result[i]);
		}
		free(result);
	}
	else
		printf("Memory allocation error\n");
	return (0);
}
 */