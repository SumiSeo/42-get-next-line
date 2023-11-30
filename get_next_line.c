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
	char	*temp;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(bassin_buffer);
	temp = ft_calloc(len, sizeof(char));
	if (!temp)
		return (NULL);
	while (bassin_buffer[i] != '\n')
	{
		temp[i] = bassin_buffer[i];
		i++;
	}
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

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!bassin_buffer)
		bassin_buffer = ft_calloc(1, sizeof(char));
	if (!ft_strchr(bassin_buffer, '\n'))
		bassin_buffer = read_line(bassin_buffer, fd);
	if (!bassin_buffer)
		return (free(bassin_buffer), NULL);
	line = extract_line(bassin_buffer);
	bassin_buffer = obtain_remaining(bassin_buffer);
	return (line);
}

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("poem.txt", O_RDONLY);
	while (i < 8)
	{
		printf("Final [%s]\n", get_next_line(fd));
		i++;
	}
	close(fd);
}
