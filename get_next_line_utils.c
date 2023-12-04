/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:42:39 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/04 17:41:27 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int has_newline(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if(str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *till_nl(char *content)
{
	char *output;
	int i;

	i = 0;
	if (!content)
		return (NULL);
	output = (char *)malloc(ft_strlen(content) + 1);
	if (!output)
		return (NULL);
	while (content[i])
	{
		if (content[i] == '\n')
		{
			output[i] = content[i];
			break;
		}
		output[i] = content[i];
		i++;
	}
	output[i + 1] = '\0';
	return (output);
}