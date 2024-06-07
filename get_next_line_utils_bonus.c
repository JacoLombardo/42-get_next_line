/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:16:12 by jalombar          #+#    #+#             */
/*   Updated: 2024/06/07 12:33:42 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (s[len])
		len++;
	while (i < (len + 1))
	{
		if (s[i] == (char)c)
			return (s + i);
		i++;
	}
	return (NULL);
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

char	*ft_lstfree(t_list_bonus *lst)
{
	t_list_bonus	*temp;

	temp = lst;
	if (lst)
	{
		while (lst)
		{
			temp = lst->next;
			free(lst->str);
			free(lst);
			lst = temp;
		}
	}
	lst = NULL;
	return (NULL);
}

int	ft_line_length(t_list_bonus *lst)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (lst)
	{
		i = 0;
		if (lst->str == NULL)
		{
			return (len);
		}
		while (lst->str[i])
		{
			if (lst->str[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		lst = lst->next;
	}
	return (len);
}

t_list_bonus	*ft_lst_add(t_list_bonus **lst, char *str, int fd)
{
	t_list_bonus	*temp;
	t_list_bonus	*new;

	new = malloc(sizeof(t_list_bonus));
	if (!new)
		return (NULL);
	new->str = str;
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
