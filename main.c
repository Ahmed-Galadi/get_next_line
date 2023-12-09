/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:47:31 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/09 12:24:24 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//-------------------------------------//
size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

void	ft_bzero(void *s, size_t n)
{
	char			*p;
	unsigned int	x;

	x = 0;
	p = (char *)s;
	while (n > x)
	{
		p[x] = '\0';
		x++;
	}
}

char	*ft_strdup(char *s1, int b)
{
	char	*array;
	int		x;
	int		size;

	x = 0;
	size = ft_strlen(s1) + 1;
	array = malloc(size);
	if (!array)
	{
		if (b)
			return (free(s1), NULL);
		return (NULL);
	}
	while (s1[x])
	{
		array[x] = s1[x];
		x++;
	}
	array[x] = '\0';
	if (b)
		return (free(s1), array);
	return (array);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		x;
	int		y;
	char	*array;

	x = 0;
	y = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2, 0));
	if (!s2)
		return (ft_strdup(s1, 1));
	array = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!array)
		return (free(s1), NULL);
	while (s1[x])
	{
		array[x] = s1[x];
		x++;
	}
	while (s2[y])
		array[x++] = s2[y++];
	array[x] = '\0';
	return (free(s1), array);
}

int	has_newline(char *str, int *len)
{
	while (*str)
	{
		if (*str == 10)
		{
			*len += 1;
			return (1);
		}
		*len += 1;
		str++;
	}
	return (0);
}
//-------------------------------------//
char	*till_nl(char *shyata, int len)
{
	char	*array;
	int		x;

	x = 0;
	if (!shyata)
		return (0);
	array = malloc(len + 1);
	if (!array)
		return (0);
	while (shyata[x])
	{
		if (shyata[x] == '\n')
		{
			array[x] = '\n';
			break ;
		}
		else
			array[x] = shyata[x];
		x++;
	}
	array[x + 1] = '\0';
	return (array);
}

void	extract_leftover(char *shyata)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!shyata)
		return ;
	while (shyata[x])
	{
		if (shyata[x] == '\n')
		{
			x++;
			break ;
		}
		x++;
	}
	while (shyata[x])
	{
		shyata[y++] = shyata[x];
		x++;
	}
	ft_bzero(shyata + y, x - y);
}

char	*extract_nextline(char *shyata, char *all, int *has_nl)
{
	int	len;

	len = 0;
	*has_nl = has_newline(shyata, &len);
	if (*has_nl)
	{
		all = till_nl(shyata, len);
		extract_leftover(shyata);
		return (all);
	}
	else if (*has_nl == 0 && len > 0)
	{
		all = ft_strjoin(all, shyata);
		extract_leftover(shyata);
		return (all);
	}
	return (NULL);
}

char	*getline_and_free(char *shyata, char *all, int fd)
{
	int		n;
	int		len;
	char	*holder;

	len = 0;
	while (read(fd, shyata, BUFFER_SIZE))
	{
		n = has_newline(shyata, &len);
		if (n == 0)
		{
			all = ft_strjoin(all, shyata);
			extract_leftover(shyata);
		}
		else
		{
			holder = till_nl(shyata, len);
			extract_leftover(shyata);
			all = ft_strjoin(all, holder);
			return (free(holder), all);
		}
	}
	return (all);
}

char	*get_next_line(int fd)
{
	static char	shyata[BUFFER_SIZE + 1];
	char		*all;
	int			has_nl;

	if (fd < 0 || fd > OPEN_MAX || read(fd, 0, 0) < 0
		|| BUFFER_SIZE <= 0 || BUFFER_SIZE > INT32_MAX)
		return (ft_bzero(shyata, BUFFER_SIZE), NULL);
	has_nl = 0;
	all = NULL;
	all = extract_nextline(shyata, all, &has_nl);
	if (has_nl && all)
		return (all);
	all = getline_and_free(shyata, all, fd);
	if (all)
		return (all);
	return (free(all), NULL);
}
//-------------------------------------//

int main()
{
	int fd = open("txt", O_RDWR);
	char *str = get_next_line(fd);
	char *str1 = get_next_line(fd);
	char *str2 = get_next_line(fd);
	char *str3 = get_next_line(fd);
	char *str4 = get_next_line(fd);
	printf("%s%s%s%s%s", str, str1, str2,str3,str4);
	system("leaks a.out");
	free(str);
	free(str1);
	close(fd);
	return (0);
}