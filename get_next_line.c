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

char	*obtain_remaining(char *bassin_buffer)
{
	char	*temp;
	char	*newline;

	newline = ft_strchr(bassin_buffer, '\n');
	if (newline)
	{
		temp = ft_strdup(newline + 1);
		free(bassin_buffer);
		return (temp);
	}
	free(bassin_buffer);
	return (NULL);
}

char	*extract_line(char *bassin_buffer)
{
	int		i;
	char	*temp;

	i = 0;
	while (bassin_buffer[i] != '\0')
		i++;
	temp = ft_calloc(i + 1, sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (bassin_buffer[i] != '\0')
	{
		temp[i] = bassin_buffer[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
char	*append_buffer(char *bassin_buffer, char *read_buffer)
{
	char	*temp;

	temp = ft_strjoin(bassin_buffer, read_buffer);
	free(bassin_buffer);
	return (temp);
}
char	*read_line(char *bassin_buffer, int fd)
{
	int		bytes_read;
	char	*cup_buffer;

	cup_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!cup_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(cup_buffer);
			return (NULL);
		}
		cup_buffer[bytes_read] = '\0';
		bassin_buffer = append_buffer(bassin_buffer, cup_buffer);
		if (ft_strchr(bassin_buffer, '\n'))
			break ;
	}
	free(cup_buffer);
	return (bassin_buffer);
}
char	*get_next_line(int fd)
{
	static char	*bassin_buffer;
	char		*line;

	if (fd < 0 || read(fd, &line, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!bassin_buffer)
		bassin_buffer = ft_calloc(1, sizeof(char));
	if (!ft_strchr(bassin_buffer, '\n'))
		bassin_buffer = read_line(bassin_buffer, fd);
	if (!bassin_buffer)
		return (free(bassin_buffer), NULL);
	line = extract_line(bassin_buffer);
	if (line && line[0] == '\0')
	{
		free(line);
		free(bassin_buffer);
		bassin_buffer = NULL;
		return (NULL);
	}
	bassin_buffer = obtain_remaining(bassin_buffer);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	int		i;
// 	char	*s;

// 	i = 0;
// 	fd = open("poem.txt", O_RDONLY);
// 	while (i < 10)
// 	{
// 		s = get_next_line(fd);
// 		printf("Final [%s]\n", s);
// 		free(s);
// 		i++;
// 	}
// 	close(fd);
// }
