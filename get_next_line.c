/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:29:14 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/31 20:37:45 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

void	ft_lstfree(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (lst)
	{
		while (lst)
		{
			temp = lst->next;
			free(lst);
			lst = temp;
		}
	}
}

int	ft_line_length(t_list *first)
{
	int		length;
	t_list	*p;

	length = 0;
	p = first;
	while (p)
	{
		if (!ft_strchr(p->content, '\n'))
			length += ft_strlen(p->content);
		else
			length += ft_strlen(p->content) - ft_strlen(ft_strchr(p->content,
						'\n'));
		p = p->next;
	}
	return (length);
}

char	*ft_create_line(t_list *first, char *remainder)
{
	char	*line;

	line = (char *)malloc((ft_line_length(first) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_bzero(line, sizeof(line));
	while (first)
	{
		if (first->next)
			ft_strncat(line, first->content, ft_strlen(first->content));
		else
		{
			if (ft_strchr(first->content, '\n'))
			{
				ft_strncat(line, first->content, (ft_strlen(first->content)
						- ft_strlen(ft_strchr(first->content, '\n'))));
				ft_memcpy(remainder, (ft_strchr(first->content, '\n') + 1));
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
	static char	buffer[BUFFER_SIZE];
	char		*next_line;
	t_list		*lst;
	int			bytes_read;

	lst = NULL;
	bytes_read = 1;
	next_line = NULL;
	if (fd <= 0)
		return (NULL);
	if (buffer[0])
		ft_lst_add(&lst, buffer);
	while (!ft_strchr(buffer, '\n') && bytes_read)
	{
		ft_bzero(buffer, sizeof(buffer));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read)
			ft_lst_add(&lst, buffer);
	}
	if (lst)
		next_line = ft_create_line(lst, buffer);
	ft_lstfree(lst);
	return (next_line);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*temp;

	fd = 0;
	i = 1;
	temp = NULL;
	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
		{
			temp = get_next_line(fd);
			while (temp)
			{
				printf("%i-> %s\n", i, temp);
				temp = get_next_line(fd);
				i++;
			}
		}
		close(fd);
	}
	return (0);
}
