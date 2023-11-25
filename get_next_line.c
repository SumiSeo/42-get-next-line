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

char	*get_next_line(int fd)
{
	char	buffer[1024];
	int		bytesRead;

	printf("fd : %d", fd);
	bytesRead = read(fd, buffer, sizeof(buffer));
	printf("File contents : %d\n", bytesRead);
	return ("test");
}

int	main(void)
{
	int	fh;

	fh = open("poem.txt", O_RDWR);
	printf("fh[ %d]", fh);
	get_next_line(fh);
	return (0);
}
