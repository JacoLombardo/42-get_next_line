/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:29:34 by jalombar          #+#    #+#             */
/*   Updated: 2024/06/05 11:34:02 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	char			content[BUFFER_SIZE];
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
char				*ft_strchr(char *s, int c);
int					ft_strlen(char *s);
char				*ft_strncat(char *dest, char *src, int nb);
t_list				*ft_lst_add(t_list **lst, char *content);
void				*ft_memcpy(char *dest, char *src);
int					ft_line_length(t_list *first);
void				ft_bzero(char *s, size_t n);
void				ft_bzero(char *s, size_t n);
char				*ft_lstfree(t_list *lst, char *buffer, int c);