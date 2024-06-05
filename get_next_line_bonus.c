/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:19:56 by jalombar          #+#    #+#             */
/*   Updated: 2024/06/05 16:59:38 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_bufferfree(t_list_bonus *buff, int fd)
{
	t_list_bonus	*temp;

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

char	*ft_lstfree(t_list_bonus *lst, char *buffer)
{
	t_list_bonus	*temp;

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
	if (buffer)
		ft_bzero(buffer, BUFFER_SIZE);
	return (NULL);
}

int	ft_line_length(t_list_bonus *first)
{
	int				length;
	t_list_bonus	*p;

	length = 0;
	p = first;
	while (p)
	{
		if (!ft_strchr(p->content, '\n'))
			length += ft_strlen(p->content);
		else
			length += ft_strlen(p->content) - ft_strlen(ft_strchr(p->content,
						'\n')) + 1;
		p = p->next;
	}
	return (length);
}

void	ft_add_buffer(t_list_bonus **buff, t_list_bonus **lst, int fd)
{
	t_list_bonus	**temp;
	int				i;

	temp = buff;
	i = 0;
	if (*buff)
	{
		while (*buff)
		{
			if ((*buff)->fd == fd && (*buff)->content[0])
			{
				ft_lst_add(lst, (*buff)->content, fd);
				free(*buff);
				//if (i == 0)
				*buff = (*temp)->next;
			}
			else
			{
				temp = buff;
				*buff = (*buff)->next;
			}
			i++;
		}
	}
}

char	*ft_create_line_bonus(t_list_bonus *first, t_list_bonus **buff, int fd)
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
				if (BUFFER_SIZE != 1)
					ft_lst_add(buff, (ft_strchr(first->content, '\n') + 1), fd);
				return (line);
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
	static t_list_bonus	*buff;
	char				buffer[BUFFER_SIZE];
	char				*next_line;
	t_list_bonus		*lst;
	int					bytes_read;

	lst = NULL;
	bytes_read = 1;
	next_line = NULL;
	ft_bzero(buffer, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_lstfree(buff, buffer));
	ft_add_buffer(&buff, &lst, fd);
	while (!ft_strchr(buffer, '\n') && bytes_read)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read)
			ft_lst_add(&lst, buffer, fd);
	}
	if (lst)
		next_line = ft_create_line_bonus(lst, &buff, fd);
	ft_lstfree(lst, buffer);
	return (next_line);
}

/* #include <fcntl.h>

int	main(int argc, char **argv)
{
	int	fd;
	char	*temp;

	fd = 0;
	temp = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		temp = get_next_line(fd);
		free(temp);
		temp = get_next_line(fd);
		free(temp);
		temp = get_next_line(fd);
		free(temp);
		close(fd);
	}
	return (0);
} */

/* #include <fcntl.h>

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
				free(temp);
				temp = get_next_line(fd);
				i++;
			}
		}
		close(fd);
	}
	return (0);
} */

/* #include <fcntl.h>

int	main(void)
{
	int	fd1;
	int	fd2;
	int	fd3;

	fd1 = open("dummy.txt", O_RDONLY);
	fd2 = open("dum.txt", O_RDONLY);
	fd3 = open("a.txt", O_RDONLY);
	printf("1st of fd1-> %s\n", get_next_line(fd1));
	printf("1st of fd2-> %s\n", get_next_line(fd2));
	printf("1st of fd3-> %s\n", get_next_line(fd3));
	printf("2nd of fd1-> %s\n", get_next_line(fd1));
	printf("2nd of fd2-> %s\n", get_next_line(fd2));
	printf("2nd of fd3-> %s\n", get_next_line(fd3));
	printf("3rd of fd1-> %s\n", get_next_line(fd1));
	printf("3rd of fd2-> %s\n", get_next_line(fd2));
	printf("3rd of fd3-> %s\n", get_next_line(fd3));
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */
