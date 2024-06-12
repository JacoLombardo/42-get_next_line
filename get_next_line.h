/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:15:09 by jalombar          #+#    #+#             */
/*   Updated: 2024/06/12 14:59:58 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
int					ft_line_length(t_list *lst);
t_list				*ft_lst_add(t_list **lst, char *str, int fd);
char				*ft_lstfree(t_list *lst, t_list **buff, int fd);
void				ft_copy_line(t_list *list, char *line, char *buffer);
char				*ft_strchr(char *s, int c);
void				ft_free_buff(t_list **buff, int fd);

#endif