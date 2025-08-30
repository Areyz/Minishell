/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:55:22 by mgolasze          #+#    #+#             */
/*   Updated: 2025/08/23 18:11:43 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Copying from argv into the struct history and categorising them
void	parsing(char *str, t_token *parser)
{
	int	i;

	i = ft_strlen(str);
	parser.history = malloc(sizeof(char) * (i + 1));
	parser.history = ft_strcpy(str);
	if (str[0] == '|')
		parser.type = "pipe";
	else if (str[0] == '-' && str[1] != '\0')
		parser.type = "flag";
	else if (str[0] == '>' || str[0] == '<')
		parser.type = "pipe operator";
	else if ((str[0] == '>' && str[1] == '>'))
		parser.type = "double pipe operator";
	else if ((str[0] == '<' && str[1] == '<'))
		parser.type = "here_doc";
	else if //function to check if the command is valid)
		parser.type = "command";
	else
		parser.type = "value";
}

//Function for checking if our command or external one and executing it
void isourcommand(t_token *parser)
{
	if (parser.type = "command")
	{
		if (parser.history == "export")
			execute_export();
		else if (parser.history == "echo")
			execute_echo();
		else if (parser.history == "cd")
			execute_cd();
		else if (parser.history == "pwd")
			execute_pwd();
		else if (parser.history == "unset")
			execute_unset();
		else if (parser.history == "env")
			execute_env();
		else if (parser.history == "exit")
			execute_exit();
		else
			execute_other_command();
	}
}

/* 
1.check if user input is NULL (user used Ctrl+D), if yes minishel exit
2.check if string entered by the user is "\0", if yes, minishell does not have anything to parse
3.check if user input is only a space
*/
bool	parse_input(t_global *global)
{
	if (global->input == NULL)
	{
		exit(0);
		//return(false);   Without this return becaouse it does not make sense
	}
	else if (ft_strncmp(global->input, "\0", 1) == 0)
		return (false);
	else if (user_input_is_space(global->input))
		return(true);
}