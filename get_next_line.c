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
	size_t	count;

	count = get_next_line_utils(fd, BUFFER_SIZE);
	printf("Total count %zu\n", count);
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
