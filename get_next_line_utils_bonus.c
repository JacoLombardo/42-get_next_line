/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:16:12 by jalombar          #+#    #+#             */
/*   Updated: 2024/06/06 17:28:35 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *s, int size)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc((ft_zerolen(s, -2) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < size)
	{
		dup[i] = s[i];
 		i++;
	} 
	dup[i] = '\0';
	return (dup);
}

char	*ft_strc(char *s, int size, int c)
{
	char	*dup;
	int		i;

	i = -1;
	dup = NULL;
	if (size == -2)
	{
		while (++i < (ft_zerolen(s, -2) + 1))
		{
			if (s[i] == (char)c)
				return (s + i);
		}
	}
	else
	{
		dup = (char *)malloc((ft_zerolen(s, -2) + 1) * sizeof(char));
		if (!dup)
			return (NULL);
		while (++i < size)
			dup[i] = s[i];
		dup[i] = '\0';
	}
	return (dup);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (i < (ft_zerolen(s, -2) + 1))
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

/* int	ft_strlen(char *s)
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
 */
int	ft_zerolen(char *s, int n)
{
	int	i;

	i = 0;
	if (n != -2)
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

t_list_bonus	*ft_lst_add(t_list_bonus **lst, char *str, int fd,
		int bytes_read)
{
	t_list_bonus	*temp;
	t_list_bonus	*new;

	new = malloc(sizeof(t_list_bonus));
	if (!new)
		return (NULL);
	new->str = ft_strdup(str, bytes_read);
	// ft_memcpy(new->str, str, bytes_read);
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
