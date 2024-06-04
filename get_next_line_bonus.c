/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:19:56 by jalombar          #+#    #+#             */
/*   Updated: 2024/06/04 14:50:51 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_bufferfree(t_list *buff, int fd)
{
	t_list	*temp;

	temp = buff;
	if (buff)
	{
		while (buff)
		{
			temp = buff->next;
			if (buff->fd == fd)
				free(buff);
			buff = temp;
		}
	}
	return (NULL);
}

void	ft_add_buffer(t_list *buff, t_list *lst, int fd)
{
	if (buff)
	{
		while (buff)
		{
			if (buff->fd == fd && buff->content[0])
				ft_lst_add_bonus(&lst, buff->content, fd);
			buff = buff->next;
		}
	}
}

char	*ft_create_line_bonus(t_list *first, t_list *buff, int fd)
{
	char	*line;

	line = (char *)malloc((ft_line_length(first) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_bzero(line, (ft_line_length(first) + 1));
	while (first)
	{
		if (first->next)
			ft_strncat(line, first->content, ft_strlen(first->content));
		else
		{
			if (ft_strchr(first->content, '\n'))
			{
				ft_strncat(line, first->content, (ft_strlen(first->content)
						- ft_strlen(ft_strchr(first->content, '\n')) + 1));
				ft_lst_add_bonus(&buff, (ft_strchr(first->content, '\n') + 1),
					fd);
			}
			else
				ft_strncat(line, first->content, ft_strlen(first->content));
		}
		first = first->next;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*buff;
	char				buffer[BUFFER_SIZE];
	char				*next_line;
	t_list		*lst;
	int					bytes_read;

	lst = NULL;
	bytes_read = 1;
	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_bufferfree(buff, fd));
	ft_add_buffer(buff, lst, fd);
	while (!ft_strchr(buffer, '\n') && bytes_read)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read)
			ft_lst_add_bonus(&lst, buffer, fd);
		ft_bzero(buffer, BUFFER_SIZE);
	}
	if (lst)
		next_line = ft_create_line_bonus(lst, buff, fd);
	ft_lstfree(lst, buffer, 0);
	return (next_line);
}
