/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:15:09 by jalombar          #+#    #+#             */
/*   Updated: 2024/06/04 14:46:01 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>


typedef struct s_list
{
	int				fd;
	char			content[BUFFER_SIZE];
	struct t_list	*next;
}						t_list;

/* char				*get_next_line(int fd);
char				*ft_strchr(char *s, int c);
int					ft_strlen(char *s);
char				*ft_strncat(char *dest, char *src, int nb);
t_list				*ft_lst_add_bonus(t_list **lst, char *content, int fd);
void				*ft_memcpy(char *dest, char *src);
void				ft_bzero(char *s, size_t n);
int	ft_line_length(t_list *first); */
char				*ft_bufferfree(t_list *buff, int fd);
t_list				*ft_lst_add_bonus(t_list **lst, char *content, int fd);