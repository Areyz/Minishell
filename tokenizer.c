/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:55:35 by mgalecki          #+#    #+#             */
/*   Updated: 2025/09/02 19:21:55 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
initokenz() - initializes a tokenizer structure 
before parsing a command line input string 
into tokens (words, pipes, redirections, etc.).
t->str - stores the input string
t->maxw = 8 - sets the initial maximum number of words
t->maxc = 1024 - sets the maximum number of characters per token
t->word_i = -1 - Index of the current word/token. Initialized to -1 
so that the first call to next_word(t) moves it to 0.
t->letter_i = 0 - index of the current character inside the current word.
t->mode = NONE - parsing mode: determines what kind of token we’re in (WORD, SPACE, PIPE, REDIR, QUOTE).
t->modemem = NONE - saves the previous mode so the tokenizer can detect when a new token starts (e.g. switching from WORD to PIPE).
t->quote = 0 - tracks whether we are inside quotes:
0 -> no quotes, 34 (") -> double quotes, 39 (') -> single quotes.
t->array = ft_calloc(t->maxw + 1, sizeof(char *)) - Allocates memory for the token array.
Initially enough space for maxw = 8 tokens + 1 NULL terminator.
*/

void	init_token(t_token *t, char *source)
{
	t->str = source;
	t->maxw = 8;
	t->maxc = 1024;
	t->word_i = -1;
	t->letter_i = 0;
	t->mode = NONE;
	t->modemem = NONE;
	t->quote = 0; 
	t->array = ft_calloc(t->maxw + 1, sizeof(char *));
}

void	quote_check(t_token *t)
{
	if (t->mode != QUOTE)
	{
		t->quote = *t->str;
		t->str++;
		t->mode = QUOTE;
		next_word(t);
	}
	else if (t->mode == QUOTE && (*t->str == t->quote))
	{
		t->mode = NONE;
		t->quote = 0;
		t->str++;
	}
}

void	char_check(t_token *t)
{
	t->modemem = t->mode;
	if (*t->str == ' ')
		t->mode = SPACE2;
	else if(*t->str == '<' || *t->str == '>')
		t->mode = REDIR;
	else if(*t->str == '|')
		t->mode = PIPE;
	else
		t->mode = WORD;
	if (t->modemem != t->mode)
		if (t->mode != SPACE2)
			next_word(t);
}

void	process_char(t_token *t, t_global *s)
{
	// (void)t;	//temporarly foe tests - to be deleted
	// (void)s;	//temporarly foe tests - to be deleted
	if (*t->str == '$' && t->quote != 39 && t->letter_i < t->maxc)
	{
		t->str++;
		if (*t->str == '?')
			question_mark(t, s);
		else
			dolarskan(t, s);
		return ;
	}
	if (*t->str == 39 || *t->str == 34)
	{
		quote_check(t);
		return ;
	}
	if (t->quote == 0)
		char_check(t);
	if (t->mode == QUOTE || (*t->str != ' ' && *t->str != '\t'))
	{
		put_letter(t);
		t->letter_i++;
	}
	t->str++;
}

/*
tokenize() - takes the shell input string and splits it into 
tokens (words, pipes, redirections, quoted strings, etc.).
*/
char **tokenize(t_global *s)
{
	t_token	t;

	init_token(&t, s->input);
	while (*t.str)
	{
		process_char(&t, s);
	}
	t.array[t.word_i + 1] = NULL;
	return (t.array);
}