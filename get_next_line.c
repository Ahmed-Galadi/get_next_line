/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:47:22 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/09 15:14:34 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*till_nl(char *shyata, int len)
{
	char	*output;
	int		i;

	i = 0;
	if (!shyata)
		return (NULL);
	output = malloc(len + 1);
	if (!output)
		return (NULL);
	while (shyata[i])
	{
		if (shyata[i] == '\n')
		{
			output[i] = '\n';
			break ;
		}
		else
			output[i] = shyata[i];
		i++;
	}
	i += 1;
	output[i] = '\0';
	return (output);
}

void	extract_leftover(char *shyata)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!shyata)
		return ;
	while (shyata[i])
	{
		if (shyata[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	while (shyata[i])
	{
		shyata[j++] = shyata[i];
		i++;
	}
	ft_bzero(shyata + j, i - j);
}

char	*extract_nextline(char *shyata, char *output, int *has_nl)
{
	int	len;

	len = 0;
	*has_nl = has_newline(shyata, &len);
	if (*has_nl)
	{
		output = till_nl(shyata, len);
		extract_leftover(shyata);
		return (output);
	}
	else if (*has_nl == 0 && len > 0)
	{
		output = ft_strjoin(output, shyata);
		extract_leftover(shyata);
		return (output);
	}
	return (NULL);
}

char	*getline_and_free(char *shyata, char *output, int fd)
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
			output = ft_strjoin(output, shyata);
			extract_leftover(shyata);
		}
		else
		{
			holder = till_nl(shyata, len);
			extract_leftover(shyata);
			output = ft_strjoin(output, holder);
			return (free(holder), output);
		}
	}
	return (output);
}

char	*get_next_line(int fd)
{
	static char	shyata[BUFFER_SIZE + 1];
	char		*output;
	int			has_nl;

	if (fd < 0 || fd > 10240 || read(fd, 0, 0) < 0
		|| BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (ft_bzero(shyata, BUFFER_SIZE), NULL);
	has_nl = 0;
	output = NULL;
	output = extract_nextline(shyata, output, &has_nl);
	if (has_nl && output)
		return (output);
	output = getline_and_free(shyata, output, fd);
	if (output)
		return (output);
	return (free(output), NULL);
}
