/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolasze <mgolasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:55:29 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/11 17:23:24 by mgolasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//basic lexer for tokenising and categorising
// char	lexer(char *r_line)
void	lexer(char *r_line)
{
	int			i;
	//t_token		next;
	//t_token		new;

	t_enviro	*env;

	char	**tokens;
	
	tokens = ft_split(r_line, ' '); //creating list of tokens
				//for now we only consider single space
				//remember to free
	env = env_init(tokens);
	i = 0;
	while(tokens[i++])
		free(tokens[i]);
	free(tokens);

	i = 0;
	while(env) //print every node of t_enviro
	//todo - linked list with next and prev
	{
		printf("env[%d] = %s\n",i, env->content);
		env = env->next;
		i++;
	}
}
