/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:47:31 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/08 18:46:23 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

///-----------------
int has_newline(char *str, int *len)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if(str[i] == '\n')
		{
			*len+=1;
			return (1);
		}
		i++;
		*len+=1;
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
	char		*joined;
	int			i;
	int			j;

	if (!s1 && !s2)
		return (NULL);
	joined = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return (free(s1), free(s2), NULL);
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
	if (!content)
		return (NULL);
	while (content[i] != '\n' && content[i])
		i++;
	if (!content[i])
		return (free(content),NULL);
	i += 1;
	output = (char *)malloc(ft_strlen(content + i) + 1);
	if(!output)
		return (free(content),NULL);
	while (content[i])
	{
		output[j] = content[i];
		i++;
		j++;
	}
	output[i] = '\0';
	return (free(content),output);
}
//------------------------
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
		if(check_nl && !buffer)
		{
			buffer = ft_strjoin(buffer, till_nl(shyata));
			shyata = shyata_to_static(shyata);
			return (buffer);
		}
		else if (!check_nl && !buffer)
		{
			
			buffer = ft_strjoin(buffer, shyata);
			shyata = shyata_to_static(shyata);		
			
		}
	}
	if(buffer)
	{
		return (buffer);
	}
	return (NULL);
}

//------------------------
int main()
{
	int fd = open("txt", O_RDWR);
	// char *str = get_next_line(fd);
	// char *str1 = get_next_line(fd);
	// char *str2 = get_next_line(fd);
	// char *str3 = get_next_line(fd);
	// char *str4 = get_next_line(fd);
	// printf("%s%s%s%s%s", str, str1, str2,str3,str4);
	//system("leaks a.out");
	// free(str);
	// free(str1);
	char *s;
	int i = 0;
	while (i < 5)
	{
		s = get_next_line(fd);
		printf("%s",s);
		i++;
	}
	
	close(fd);
	return (0);
}