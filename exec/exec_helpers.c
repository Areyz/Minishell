/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjamrosz <kjamrosz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:43:02 by kjamrosz          #+#    #+#             */
/*   Updated: 2025/08/31 18:47:03 by kjamrosz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*multicat(char	**input)
{
	ssize_t			total_length;
	unsigned int	s_counter;
	unsigned int	s_index;
	char			*result;

	total_length = 0;
	s_counter = 0;
	s_index = 0;
	while (input[s_counter] != NULL)
	{
		total_length += ft_strlen(input[s_counter]);
		s_counter++;
	}
	result = ft_calloc(total_length + 8, sizeof(char));
	while (s_index < s_counter)
	{
		ft_strlcat(result, input[s_index], total_length + 8);
		s_index++;
	}
	result[total_length + 1] = 0;
	return (result);
}

char	*next_folder(t_global *global, int *offset)
{
	unsigned int	len;
	char			*str;
	ssize_t			cap;
	char			*result;

	len = 0;
	str = (var_to_value("PATH", global->env_list, 4));
	cap = ft_strlen(str);
	result = ft_calloc(cap + 1, sizeof(char));
	if (*offset + len >= cap)
		return (result);
	while (str[*offset + len] != ':' && *offset + len < cap)
	{
		len++;
	}
	ft_strncpy(result, &str[*offset], len);
	*offset = *offset + len + 1;
	return (result);
}