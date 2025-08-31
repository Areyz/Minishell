/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:55:07 by mgalecki          #+#    #+#             */
/*   Updated: 2025/08/31 15:55:10 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**str_array_realloc(char **old, size_t add_slots)
{
	size_t	i;
	size_t	j;
	char	**new;

	i = 0;
	while (old && old[i])
		i++;
	new = malloc(sizeof(char *) * (i + add_slots + 1));
	if (!new)
		return(NULL);
	j = 0;
	while (j < i)
	{
		new[j] = old[j];
		j++;
	}
	while (j < i + add_slots)
	{
		new[j] = NULL;
		j++;
	}
	new[j] = NULL;
	fre(old);
	return (new);
}

void	next_word(t_token *t)
{
	int	grow_amount;

	grow_amount = 8;
	t->word_i += 1;
	t->letter_i = 0;
	if (t->word_i >= t->maxw)
	{
		t->maxw += grow_amount;
		t->array = str_array_realloc(t->array, grow_amount);
		if (!t->array)
		{
			perror("realloc failed");
			exit(1);
		}
	}
	t->array[t->word_i] = ft_calloc(t->maxc, sizeof(char));
}

void	question_mark(t_token *t, t_global *s)
{
	char	*exitcode_str;

	if (t->quote != 34)
	{
		next_word(t);
		t->mode = DOLLAR;
	}
	t->str++;
	exitcode_str = ft_itoa(s->last_exit_code);
	ft_strlcat(&t->array[t->word_i][t->letter_i], exitcode_str, t->maxc - t->letter_i);
	t->letter_i += ft_strlen(exitcode_str);
	free(exitcode_str);
}

void	dolarskan(t_token *t, t_global *s)
{
	char			*start;
	char			*end;
	unsigned int	n;

	if (t->quote != 34)
	{
		next_word(t);
		t->mode = DOLLAR;
	}
	start = t->str;
	end = start;
	while ((ft_isalnum(*end) || *end == '_') && *end)
		end++;
	n = end - start;
	t->str += n;
	if (*var_to)
}