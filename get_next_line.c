/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:47:22 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/08 17:21:05 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	static char *shyata;
	char		*buffer;
	int			check_nl;
	int			len = 0;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (read(fd, 0, 0) == -1 || fd < 0)
		return (NULL);
	buffer = NULL;
	if(!shyata)
	{
		shyata = (char *)malloc(BUFFER_SIZE + 1);
		if(!shyata)
			return (NULL);
	}
	else 
	{
		check_nl = has_newline(shyata, &len);
		if(check_nl)
		{
			buffer = till_nl(shyata);
			shyata = shyata_to_static(shyata);
			return (buffer);
		}
		else if (check_nl == 0 && len != 0)
		{
			buffer = till_nl(shyata);	
			shyata = shyata_to_static(shyata);
		}
	}
	while(read(fd, shyata, BUFFER_SIZE))
	{
		check_nl = has_newline(shyata, &len);
		if(check_nl)
		{
			buffer = ft_strjoin(buffer, till_nl(shyata));
			shyata = shyata_to_static(shyata);
			return (buffer);
		}
		else if (check_nl == 0)
			buffer = ft_strjoin(buffer, shyata);
	}
	if(buffer)
		return (buffer);
	return (NULL);
}
