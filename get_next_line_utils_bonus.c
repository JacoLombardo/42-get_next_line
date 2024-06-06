/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:16:12 by jalombar          #+#    #+#             */
/*   Updated: 2024/06/06 12:35:11 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(char *dest, char *src, int size)
{
	int	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (i < (ft_strlen(s) + 1))
	{
		if (s[i] == (char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strncat(char *dest, char *src, int nb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (i < nb && src[i])
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}

int	ft_lenandzero(char *s, char c, size_t n)
{
	size_t	i;

	i = 0;
	if (c == 'z')
	{
		while (i < n)
		{
			s[i] = '\0';
			i++;
		}
		return (0);
	}
	else
	{
		while (s[i])
			i++;
		return (i);
	}
}

t_list_bonus	*ft_lst_add(t_list_bonus **lst, char *content, int fd,
		int bytes_read)
{
	t_list_bonus	*temp;
	t_list_bonus	*new;

	new = malloc(sizeof(t_list_bonus));
	if (!new)
		return (NULL);
	ft_memcpy(new->content, content, bytes_read);
	new->content[bytes_read] = '\0';
	new->fd = fd;
	new->next = NULL;
	temp = *lst;
	if (*lst)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*lst = new;
	return (new);
}
