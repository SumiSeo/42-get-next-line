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
int					len_to_newline(t_list *list);
void				dealloc(t_list **list, t_list *clean_node, char *buf);
void				copy_str(t_list *list, char *str);
t_list				*find_last_node(t_list *list);
int					found_newline(t_list *list);
char				*get_line(t_list *list);
void				append(t_list **list, char *buf);
void				create_list(t_list **list, int fd);
char				*get_next_line(int fd);

#endif
