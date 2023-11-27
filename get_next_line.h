/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:21:30 by sumseo            #+#    #+#             */
/*   Updated: 2023/11/25 15:23:39 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}					t_list;

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char				*get_next_line(int fd);
static int			len_to_newline(t_list *list);
static void			dealloc(t_list **list, t_list *clean_node, char *buf);
static void			copy_str(t_list *list, char *str);
static t_list		*find_last_node(t_list *list);
static int			found_newline(t_list *list);
static char			*get_line(t_list *list);
static void			append(t_list **list, char *buf);
static void			create_list(t_list **list, int fd);
static char			*get_next_line(int fd);

#endif
