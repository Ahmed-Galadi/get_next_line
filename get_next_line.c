/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:47:22 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/04 00:28:19 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

char *till_nl(char *output, char *shyata)
{
}

char *get_next_line(int fd)
{
	char *holder = NULL;
	int buff_size;
	buff_size = 10;
	char content[buff_size + 1];
	int read_until;
	
	
	read_until = 0;
	if (fd < 0 || buff_size <= 0)
		return (NULL);
	while(!has_newline(content))
	{
		read_until = read(fd, content, buff_size);
		content[read_until] = '\0';
		holder = ft_strjoin(holder, content);
	}
	
	return (holder);
}
