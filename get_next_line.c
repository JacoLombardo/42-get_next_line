/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:29:14 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/23 17:23:03 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_create_line(t_list *first)
{
	char	*line;
	int		len;

	len = ft_line_length(first);
	line = (char *)malloc((len + 1) * sizeof(char));
	while (first)
	{
		if (first->next)
			ft_strncat(line, first->content, ft_strlen(first->content));
		else
			ft_strncat(line, first->content, (ft_strlen(first->content)
					- ft_strlen(ft_strchr(first->content, '\n'))));
		first = first->next;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*next_line;
	t_list	*lst;

	lst = NULL;
	buffer = (char *)malloc(5 * sizeof(char));
	while (!ft_strchr(buffer, '\n'))
	{
		read(fd, buffer, 5);
		ft_lst_add(&lst, buffer);
	}
	next_line = ft_create_line(lst);
	ft_lstfree(lst);
	return (next_line);
}

int	main(int argc, char **argv)
{
	int	fd;

	fd = 0;
	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
			printf("P: %s\n", get_next_line(fd));
		close(fd);
	}
	return (0);
}
