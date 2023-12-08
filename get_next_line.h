/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:45:30 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/08 17:56:11 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
#include <limits.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 30
#endif
char	*get_next_line(int fd);
int		ft_strlen(char *str);
int 	has_newline(char *str, int *len);
char	*ft_strjoin(char *s1, char *s2);
char	*till_nl(char *content);
char	*shyata_to_static(char *content);
#endif
