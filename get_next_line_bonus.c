/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:47:22 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/13 17:02:58 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*till_nl(char *leftover, int len)
{
	char	*output;
	int		i;

	i = 0;
	if (!leftover)
		return (NULL);
	output = malloc(len + 1);
	if (!output)
		return (NULL);
	while (leftover[i])
	{
		if (leftover[i] == '\n')
		{
			output[i] = '\n';
			break ;
		}
		else
			output[i] = leftover[i];
		i++;
	}
	i++;
	output[i] = '\0';
	return (output);
}

static void	extract_leftover(char *leftover)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!leftover)
		return ;
	while (leftover[i])
	{
		if (leftover[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	while (leftover[i])
	{
		leftover[j++] = leftover[i];
		i++;
	}
	ft_bzero(leftover + j, i - j);
}

static char	*extract_nextline(char *leftover, char *output, int *has_nl)
{
	int	len;

	len = 0;
	*has_nl = has_newline(leftover, &len);
	if (*has_nl)
	{
		output = till_nl(leftover, len);
		extract_leftover(leftover);
		return (output);
	}
	else if (*has_nl == 0 && len > 0)
	{
		output = ft_strjoin(output, leftover);
		extract_leftover(leftover);
		return (output);
	}
	return (NULL);
}

static char	*getline_and_free(char *leftover, char *output, int fd)
{
	int		has_nl;
	int		len;
	char	*holder;

	len = 0;
	while (read(fd, leftover, BUFFER_SIZE))
	{
		has_nl = has_newline(leftover, &len);
		if (has_nl == 0)
		{
			output = ft_strjoin(output, leftover);
			extract_leftover(leftover);
		}
		else
		{
			holder = till_nl(leftover, len);
			extract_leftover(leftover);
			output = ft_strjoin(output, holder);
			return (free(holder), output);
		}
	}
	return (output);
}

char	*get_next_line(int fd)
{
	static char	leftover[OPEN_MAX][BUFFER_SIZE + 1];
	char		*output;
	int			has_nl;

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	if (read(fd, 0, 0) < 0
		|| BUFFER_SIZE <= 0
		|| BUFFER_SIZE > 2147483647)
		return (ft_bzero(leftover[fd], BUFFER_SIZE), NULL);
	has_nl = 0;
	output = NULL;
	output = extract_nextline(leftover[fd], output, &has_nl);
	if (has_nl && output)
		return (output);
	output = getline_and_free(leftover[fd], output, fd);
	if (output)
		return (output);
	return (free(output), NULL);
}
