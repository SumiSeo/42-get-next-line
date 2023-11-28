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

static int	find_new_line(void *p)
{
	if (p == '\n')
		return (1);
	return (0);
}

char	*create_list(t_list *list, int fd)
{
	char	buf[BUFFER_SIZE];
	int		read_size;
	t_list	*new_str;
	int		len;

	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		// printf("Total size [%d], Buf [%.*s]\n", read_size, read_size, buf);
		// buf[read_size] = '\0';
		new_str = ft_lstnew(buf);
		printf("new string [%s]\n", new_str->str_buf);
		ft_lstadd_back(&list, new_str);
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	printf("@@@@List check :[%s]", list->str_buf);
	len = ft_lstsize(list);
	printf("@@@@List length :[%d]", len);
	if (!list)
		return (NULL);
	ft_lstiter(buf, find_new_line);
	return ("Test");
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(list, fd);
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