/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:20:07 by sumseo            #+#    #+#             */
/*   Updated: 2023/11/25 15:20:33 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 10000

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		count;
	int		fb;
	char	r_buffer[BUFFER_SIZE];
	int		nb_read;

	fb = 1;
	count = 0;
	nb_read = -1;
	// printf("fd : %d\n", fd);
	if (fd == -1)
		return ("test");
	// printf("File contents : %s\n", buffer);
	while ((nb_read = read(fd, buffer, fb)) > 0)
	{
		if (buffer[0] == '\n' || buffer[0] == '\r')
		{
			printf("Looking for enter key : [%c]\n", buffer[0]);
		}
		buffer[nb_read] = '\0';
		r_buffer[count] = buffer[0];
		// printf("** NB Read : %d", nb_read);
		// If buffer size is small,
		// it does not read everythiing so I have to control this.
		// If it is smaller  ->
		// But how to check  it ends of the line ?
		// If I find enter key ? in the file
		count++;
	}
	printf("**Count : %d and Buffer : %s\n", count, r_buffer);
	if (nb_read == -1)
	{
		printf("READ ERROR\n");
		return ("test");
	}
	return ("test");
}

int	main(void)
{
	int		fh;
	FILE	*fho;

	fh = open("poem.txt", O_RDWR);
	// printf("fh[ %d]", fh);
	fho = fopen("poem.txt", "r");
	get_next_line(fh);
	return (0);
}
