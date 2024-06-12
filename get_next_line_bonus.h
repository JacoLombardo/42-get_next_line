/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:15:09 by jalombar          #+#    #+#             */
/*   Updated: 2024/06/12 15:01:07 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list_bonus
{
	int					fd;
	char				*content;
	struct s_list_bonus	*next;
}						t_list_bonus;

char					*get_next_line(int fd);
int						ft_line_length(t_list_bonus *lst);
t_list_bonus			*ft_lst_add(t_list_bonus **lst, char *str, int fd);
char					*ft_lstfree(t_list_bonus *lst, t_list_bonus **buff,
							int fd);
void					ft_copy_line(t_list_bonus *list, char *line,
							char *buffer);
char					*ft_strchr(char *s, int c);
void					ft_free_buff(t_list_bonus **buff, int fd);

#endif