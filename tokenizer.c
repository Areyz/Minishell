
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
t->letter_i = 0 - Index of the current character inside the current word.
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

void	process_char(t_token *t, t_global *s)
{
	(void)t;	//temporarly foe tests - to be deleted
	(void)s;	//temporarly foe tests - to be deleted
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