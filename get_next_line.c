/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:47:22 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/07 14:04:15 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	static char *shyata;
	char *holder = NULL;
	int buff_size;
	buff_size = BUFFER_SIZE;
	char content[buff_size + 1];
	int read_until;

	read_until = 0;
	if (fd < 0 || buff_size <= 0)
		return (NULL);
	if (shyata)
		holder = ft_strjoin(holder, shyata);
	while(!has_newline(content))
	{
		read_until = read(fd, content, buff_size);
		content[read_until] = '\0';
		free(holder);
		holder = ft_strjoin(holder, content);
	}
	if (shyata != NULL)
		free(shyata);
	shyata = shyata_to_static(holder);
	free(holder);
	return (till_nl(holder));
}

