/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:47:22 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/01 23:18:47 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int has_newline(char *str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		if(str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	static my_list *list_buff;
	char *output;
	size_t buff_size;
	
	buff_size = 10;
	if (fd < 0 || buff_size >= 0)
		return (NULL);
	
	while(1)
	{
		read(fd, list_buff->str, 10);
		if(has_newline(list_buff->str))
		{
			
		}
		list_buff = list_buff->next;
	}
	return (output);
}