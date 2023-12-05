/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:45:30 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/05 14:19:07 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif
char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		has_newline(char *str);
char	*till_nl(char *content);
char	*shyata_to_static(char *content);
#endif
