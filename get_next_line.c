/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:47:22 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/04 17:41:32 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>



int ft_strlen(char *str)
{
	int		i;

	i = 0;
	while(str && str[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	static char *shyata;
	char		*joined;
	int			i;
	int			j;

	joined = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while(s2 && s2[j])
	{
		joined[i] = s2[j];
		j++;
		i++;
	}
	joined[i] = '\0';
	return (joined);
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

char *get_next_line(int fd)
{
	static char *shyata = NULL;
	char *holder = NULL;
	int buff_size;
	buff_size = 10;
	char content[buff_size + 1];
	int read_until;

	read_until = 0;
	if (fd < 0 || buff_size <= 0)
		return (NULL);
	if (shyata)
	{
		holder = ft_strjoin(holder, shyata);
		free(shyata);	
	}
	while(!has_newline(content))
	{
		read_until = read(fd, content, buff_size);
		content[read_until] = '\0';
		holder = ft_strjoin(holder, content);
	}
	shyata = shyata_to_static(holder);
	free(holder);
	return (till_nl(holder));
}

