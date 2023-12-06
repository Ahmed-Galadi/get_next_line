/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:47:31 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/06 23:44:24 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	// int fd = open("txt", O_RDWR);
	// char *str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
	// char *str1 = get_next_line(fd);
	// printf("%s", str1);
	// free(str1);
	// char *str2 = get_next_line(fd);
	// printf("%s", str2);
	// free(str2);
	// char *str3 = get_next_line(fd);
	// printf("%s", str3);
	// free(str3);
	// char *str4 = get_next_line(fd);
	// printf("%s", str4);
	// free(str4);
	// system("leaks a.out");
	// close(fd);
	char *str = malloc(10);
	str[0] = 'a';
	str[1] = '\0';
	free(str);
	printf("%s", str);
	return (0);
}