/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:47:22 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/03 10:51:35 by agaladi          ###   ########.fr       */
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
	while(str[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2, int buffsize)
{
	static int	size;
	char		*joined;
	int			i;
	int			j;

	size += buffsize;
	joined = (char *)malloc(size + 1);
	i = -1;
	j = -1;
	while (s1[++i])
		joined[i] = s1[i];
	while(s2[j])
		joined[++i] = s2[++j];
	joined[i] = '\0';
	return (joined);
}

char *get_next_line(int fd)
{
	char *output;
	int buff_size;
	buff_size = 10;
	char content[11] = "\0";
	int read_until;

	if (fd < 0 || buff_size <= 0)
		return (NULL);
	while(!has_newline(content))
	{
		read_until = read(fd, content, buff_size);
		content[read_until] = '\0';
		output = ft_strjoin(output, content, buff_size);
	}
	printf("%s", output);
	
	return (output);
}