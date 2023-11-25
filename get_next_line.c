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

#define BUFFER_SIZE 5

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		bytesRead;

	printf("fd : %d", fd);
	bytesRead = read(fd, buffer, BUFFER_SIZE);
	printf("File contents : %d\n", bytesRead);
	printf("File contents %s\n", buffer);
	return ("test");
}

int	main(void)
{
	int	fh;

	fh = open("poem2.txt", O_RDWR);
	printf("fh[ %d]", fh);
	get_next_line(fh);
	return (0);
}
