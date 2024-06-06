/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:15:09 by jalombar          #+#    #+#             */
/*   Updated: 2024/06/06 17:11:21 by jalombar         ###   ########.fr       */
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
char					*ft_strchr(char *s, int c);
char					*ft_strncat(char *dest, char *src, int nb);
void					*ft_memcpy(char *dest, char *src, int size);
int						ft_line_length(t_list_bonus *lst);
t_list_bonus			*ft_lst_add(t_list_bonus **lst, char *str, int fd,
							int bytes_read);
char					*ft_strdup(char *s, int bytes_read);
int						ft_zerolen(char *s, int n);