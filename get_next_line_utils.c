/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:42:39 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/04 17:59:45 by agaladi          ###   ########.fr       */
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
char *shyata_to_static(char *content)
{
	char *output;
	int i;
	int j;
	i = 0;
	j = 0;
	while (content[i] != '\n')
		i++;
	if (i == 0)
		return (NULL);
	i += 1;
	output = (char *)malloc(ft_strlen(content + i) + 1);
	while (content[i])
	{
		output[j] = content[i];
		i++;
		j++;
	}
	output[i] = '\0';
	return (output);
}