/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:47:22 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/05 17:30:20 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char *ft_strjoin(char *s1, char *s2)
{
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

char *get_next_line(int fd)
{
	static char *shyata = NULL;
	char *holder = NULL;
	char content[BUFFER_SIZE + 1];
	int read_until;

	read_until = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (shyata)
		holder = ft_strjoin(holder, shyata);
	while(!has_newline(content))
	{
		read_until = read(fd, content, BUFFER_SIZE);
		content[read_until] = '\0';
		holder = ft_strjoin(holder, content);
	}
	shyata = shyata_to_static(holder);
	return (till_nl(holder));
}

