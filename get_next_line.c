/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:47:22 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/07 23:06:34 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	static char *shyata = NULL;
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

// char *get_next_line(int fd)
// {
// 	static char	*shyata;
// 	char		*output;
// 	char		*read_buff;
// 	int			read_until;

// 	read_until = 0;
// 	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd ,read_buff, 0))
// 		return (NULL);
// 	while(!has_newline(read_buff))
// 	{
// 		read_until = read(fd, read_buff, BUFFER_SIZE);
// 		if (output)
// 			free(output);
// 		output = ft_strjoin(output, read_buff);
// 		printf("%s", output);
// 	}
// 	if (shyata)
// 		free(shyata);
// 	shyata = shyata_to_static(read_buff);
// 	free(read_buff);
// 	free(output);
// 	output = till_nl(output);
// 	return (output);
// }
