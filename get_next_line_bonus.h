/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:15:09 by jalombar          #+#    #+#             */
/*   Updated: 2024/06/07 11:59:38 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list_bonus
{
	int					fd;
	char				*str;
	struct s_list_bonus	*next;
}						t_list_bonus;

char					*get_next_line(int fd);
int						ft_line_length(t_list_bonus *lst);
t_list_bonus			*ft_lst_add(t_list_bonus **lst, char *str, int fd);
char					*ft_lstfree(t_list_bonus *lst);
void					ft_copy_line(t_list_bonus *list, char *line,
							char *buffer);
void					ft_bzero(char *s, size_t n);
char					*ft_strchr(char *s, int c);