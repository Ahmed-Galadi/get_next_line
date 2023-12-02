/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:47:22 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/02 17:53:50 by agaladi          ###   ########.fr       */
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

int lenstr(char *str)
{}

char *joining(char *s1, char *s2)
{
	int s1_length;
	int s2_length;
}

char *get_next_line(int fd)
{
	static my_list *list_buff;
	char *output;
	int buff_size;
	buff_size = 10;
	my_list *curr;
	char content[11] = "\0";
	int read_until;
	
	output = "";
	if (fd < 0 || buff_size <= 0)
		return (NULL);
	curr = list_buff;
	while(!has_newline(content))
	{
		read_until = read(fd, content, buff_size);
		content[read_until] = '\0';
		list_buff = ft_lstnew(content);
		printf("%s", list_buff->str);
		ft_lstadd_back(&curr, ft_lstnew(content));
		curr = curr->next;
	}
	
	return (output);
}