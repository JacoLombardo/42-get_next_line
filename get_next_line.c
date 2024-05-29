/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:29:14 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/29 14:56:19 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstfree(t_list *lst, char *buffer)
{
	t_list	*temp;

	temp = lst;
	if (buffer)
		free(buffer);
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

char	*ft_create_line(t_list *first, char **remainder)
{
	char	*line;
	int		len;

	/* printf("FIRST: %s <-\n", first->content);
	printf("FIRST+: %s <-\n", first->next->content); */
	len = ft_line_length(first);
	line = (char *)malloc((len + 1) * sizeof(char));
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
				*remainder = ft_strdup(ft_strchr(first->content, '\n')) + 1;
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
	char		*buffer;
	char		*next_line;
	static char	*remainder;
	t_list		*lst;
	int			bytes_read;

	lst = NULL;
	bytes_read = 1;
	next_line = NULL;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	if (remainder)
	{
		ft_lst_add(&lst, remainder);
		remainder = NULL;
	}
	while (!ft_strchr(buffer, '\n') && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		//if (lst)
			//printf("REMAINDER: %s\n", lst->content);
		//printf("BUFF_SIZE: %i\n", ft_strlen(buffer));
		//printf("BYTES: %i\n", bytes_read);
		//printf("BUFF: %s\n", buffer);
		if (bytes_read)
			ft_lst_add(&lst, buffer);
	}
	if (lst)
		next_line = ft_create_line(lst, &remainder);
	ft_lstfree(lst, buffer);
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

/* printf("1-> %s\n", get_next_line(fd));
printf("2-> %s\n", get_next_line(fd));
printf("3-> %s\n", get_next_line(fd));
printf("4-> %s\n", get_next_line(fd));
printf("5-> %s\n", get_next_line(fd));
printf("6-> %s\n", get_next_line(fd)); */