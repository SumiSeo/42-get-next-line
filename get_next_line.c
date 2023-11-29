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

char	*create_str(char *str, int fd)
{
	char	buf[1];
	int		read_size;
	int		count;

	count = 1;
	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		free(str);
	read_size = read(fd, buf, 1);
	str[0] = *buf;
	while (read_size > 0)
	{
		read_size = read(fd, buf, 1);
		if (*buf == '\n')
		{
			break ;
		}
		printf("Read string [%s]\n", buf);
		str[count] = *buf;
		count++;
	}
	printf("Original string [%s]\n", str);
	// ft_lstiter(buf, find_new_line);
	return ("Test");
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*next_line;

	// static t_list	*list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	// create_list(list, fd);
	create_str(str, fd);
	// if (list == NULL)
	// 	return (NULL);
	// next_line = get_line(list);
	// polish_list(&list);
	// return (next_line);
	return ("test");
}
int	main(void)
{
	int fd;

	fd = open("poem.txt", O_RDONLY);
	printf("Final [%s]\n", get_next_line(fd));
}