/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:20:49 by sumseo            #+#    #+#             */
/*   Updated: 2023/11/25 15:21:18 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_next_line_utils(int fd, int size)
{
	size_t	count;
	int		fb;
	char	*buffer[size];
	int		nb_read;

	fb = 1;
	count = 0;
	nb_read = -1;
	if (fd == -1)
		return (1);
	while ((nb_read = read(fd, buffer, 1)) > 0)
		count++;
	return (count);
}
