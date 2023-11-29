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

char	*create_first_line(char *str, int fd)
{
	char	buf[1];
	int		read_size;
	int		count;
	size_t	len;

	count = 0;
	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 2);
	if (!str)
		return (NULL);
	read_size = read(fd, buf, 1);
	while (read_size > 0)
	{
		if (*buf == '\n')
			break ;
		str[count] = *buf;
		count++;
		read_size = read(fd, buf, 1);
	}
	len = ft_strlen(str);
	str[len] = '\0';
	str[len + 1] = '\n';
	count = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	char	*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	return (create_first_line(next_line, fd));
}

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("poem.txt", O_RDONLY);
	while (i < 3)
	{
		printf("Final [%s]\n", get_next_line(fd));
		i++;
	}
}
