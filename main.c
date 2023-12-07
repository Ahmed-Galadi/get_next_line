/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:47:31 by agaladi           #+#    #+#             */
/*   Updated: 2023/12/07 23:13:34 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("txt", O_RDWR);
	char *str = get_next_line(fd);
	char *str1 = get_next_line(fd);
	// char *str2 = get_next_line(fd);
	// char *str3 = get_next_line(fd);
	// char *str4 = get_next_line(fd);
	// char *str5 = get_next_line(fd);
	// char *str6 = get_next_line(fd);
	// char *str7 = get_next_line(fd);
	// char *str8 = get_next_line(fd);
	// char *str9 = get_next_line(fd);
	// printf("%s%s%s%s%s%s%s%s%s%s", str, str1, str2, str3, str4, str5, str6, str7, str8, str9);
	printf("%s", str);
	printf("%s", str1);
	free(str);
	free(str1);
	// free(str2);
	// free(str3);
	// free(str4);
	// free(str5);
	// free(str6);
	// free(str7);
	// free(str8);
	// free(str9);
	close(fd);
	return (0);
}