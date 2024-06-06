/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:19:56 by jalombar          #+#    #+#             */
/*   Updated: 2024/06/06 17:09:44 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_lstfree(t_list_bonus *lst, char *buffer)
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
	if (buffer)
		free(buffer);
	return (NULL);
}

int	ft_line_length(t_list_bonus *lst)
{
	int				length;
	t_list_bonus	*p;

	length = 0;
	p = lst;
	while (p)
	{
		if (!ft_strchr(p->str, '\n'))
			length += ft_zerolen(p->str, -2);
		else
			length += ft_zerolen(p->str, -2) - ft_zerolen(ft_strchr(p->str,
						'\n'), -2) + 1;
		p = p->next;
	}
	return (length);
}

void	ft_add_buffer(t_list_bonus **buff, t_list_bonus **lst, int fd)
{
	t_list_bonus	*temp;
	t_list_bonus	*prev;
	t_list_bonus	*current;

	current = *buff;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd && current->str[0])
		{
			ft_lst_add(lst, current->str, fd, ft_zerolen(current->str, -2));
			if (prev)
				prev->next = current->next;
			else
				*buff = current->next;
			temp = current;
			current = current->next;
			free(temp->str);
			free(temp);
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

char	*ft_create_line_bonus(t_list_bonus *first, t_list_bonus **buff, int fd)
{
	char	*line;

	line = (char *)malloc((ft_line_length(first) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_zerolen(line, (ft_line_length(first) + 1));
	while (first)
	{
		if (first->next)
			ft_strncat(line, first->str, ft_zerolen(first->str, -2));
		else
		{
			if (ft_strchr(first->str, '\n'))
			{
				ft_strncat(line, first->str, (ft_zerolen(first->str, -2)
						- ft_zerolen(ft_strchr(first->str, '\n'), -2) + 1));
				if (ft_strchr(first->str, '\n')[1])
					ft_lst_add(buff, (ft_strchr(first->str, '\n') + 1), fd,
						ft_zerolen(ft_strchr(first->str, '\n') + 1, -2));
				return (line);
			}
			else
				ft_strncat(line, first->str, ft_zerolen(first->str, -2));
		}
		first = first->next;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list_bonus	*buff;
	char				*buffer;
	char				*next_line;
	t_list_bonus		*lst;
	int					bytes_read;

	lst = NULL;
	bytes_read = 1;
	next_line = NULL;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer || fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_lstfree(lst, buffer));
	ft_add_buffer(&buff, &lst, fd);
	ft_zerolen(buffer, (BUFFER_SIZE + 1));
	while (!ft_strchr(buffer, '\n') && bytes_read)
	{
		if (lst && ft_strchr(lst->str, '\n'))
			break ;
		ft_zerolen(buffer, (BUFFER_SIZE + 1));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		//buffer[bytes_read] = '\0';
		if (bytes_read)
			ft_lst_add(&lst, buffer, fd, bytes_read);
	}
	if (lst)
		next_line = ft_create_line_bonus(lst, &buff, fd);
	ft_lstfree(lst, buffer);
	return (next_line);
}

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
	int	fd1, fd2;
	char *line;

	fd1 = open("read_error.txt", O_RDONLY);
	fd2 = open("lines_around_10.txt", O_RDONLY);

	line = get_next_line(fd1);
	printf("1-> %s\n", line);
	free(line);

	line = get_next_line(fd2);
	printf("2-> %s\n", line);
	free(line);

	line = get_next_line(fd1);
	printf("3-> %s\n", line);
	free(line);

	line = get_next_line(fd2);
	printf("4-> %s\n", line);
	free(line);


	line = get_next_line(fd1);
	free(line);
	line = get_next_line(fd1);
	free(line);
	line = get_next_line(fd1);
	printf("5-> %s\n", line);
	free(line);
	close(fd1);

	line = get_next_line(fd2);
	printf("6-> %s\n", line);
	free(line);

	fd1 = open("read_error.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("7-> %s\n", line);
	free(line);

	line = get_next_line(fd2);
	printf("8-> %s\n", line);
	free(line);

	line = get_next_line(fd1);
	printf("9-> %s\n", line);
	free(line);
	line = get_next_line(fd1);
	printf("10-> %s\n", line);
	free(line);

	line = get_next_line(fd2);
	printf("11-> %s\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("12-> %s\n", line);
	free(line);

	line = get_next_line(fd1);
	printf("13-> %s\n", line);
	free(line);
	line = get_next_line(fd1);
	printf("14-> %s\n", line);
	free(line);

	close(fd1);
	close(fd2);


	return (0);
}
 */