/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:29:34 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/24 14:48:14 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 10

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
char				*ft_strchr(const char *s, int c);
int					ft_strlen(const char *s);
char				*ft_strncat(char *dest, char *src, int nb);
t_list				*ft_lst_add(t_list **lst, char *content);
char				*ft_strdup(const char *s);