/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:02:05 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/13 17:02:40 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *ptr, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)ptr;
	i = 0;
	while (i < n)
		*(str + i++) = '\0';
}

int	has_newline(char *str, int *len)
{
	while (*str)
	{
		if (*str == '\n')
		{
			*len += 1;
			return (1);
		}
		*len += 1;
		str++;
	}
	return (0);
}

char	*ft_strdup(char *s1, int should_free)
{
	char	*output;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s1) + 1;
	output = malloc(size);
	if (!output)
	{
		if (should_free)
			return (free(s1), NULL);
		return (NULL);
	}
	while (s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	output[i] = '\0';
	if (should_free)
		return (free(s1), output);
	return (output);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*output;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2, 0));
	if (!s2)
		return (ft_strdup(s1, 1));
	output = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!output)
		return (free(s1), NULL);
	while (s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	while (s2[j])
		output[i++] = s2[j++];
	output[i] = '\0';
	return (free(s1), output);
}
