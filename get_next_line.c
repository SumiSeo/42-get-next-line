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

// static int	find_new_line(void *p)
// {
// 	if (p == '\n')
// 		return (1);
// 	return (0);
// }

// char	*create_list(t_list *list, int fd)
// {
// 	char	buf[BUFFER_SIZE];
// 	int		read_size;
// 	t_list	*new_str;
// 	int		len;

// 	read_size = read(fd, buf, BUFFER_SIZE);
// 	while (read_size > 0)
// 	{
// 		// printf("Total size [%d], Buf [%.*s]\n", read_size, read_size, buf);
// 		// buf[read_size] = '\0';
// 		new_str = ft_lstnew(buf);
// 		printf("new string [%s]\n", new_str->str_buf);
// 		ft_lstadd_back(&list, new_str);
// 		read_size = read(fd, buf, BUFFER_SIZE);
// 	}
// 	printf("@@@@List check :[%s]", list->str_buf);
// 	len = ft_lstsize(list);
// 	printf("@@@@List length :[%d]", len);
// 	if (!list)
// 		return (NULL);
// 	// ft_lstiter(buf, find_new_line);
// 	return ("Test");
// }

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
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	return (create_first_line(str, fd));
}

int	main(void)
{
	int fd;
	int i = 0;

	fd = open("poem.txt", O_RDONLY);
	while (i < 3)
	{
		printf("Final [%s]\n", get_next_line(fd));
		i++;
	}
}