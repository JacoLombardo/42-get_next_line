/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:19:56 by jalombar          #+#    #+#             */
/*   Updated: 2024/06/07 14:52:26 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			ft_lst_add(lst, current->str, fd);
			if (prev)
				prev->next = current->next;
			else
				*buff = current->next;
			temp = current;
			current = current->next;
			free(temp);
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

char	*ft_create_line(t_list_bonus *lst, t_list_bonus **buff, int fd)
{
	char	*line;
	char	*buffer;

	line = (char *)malloc((ft_line_length(lst) + 1) * sizeof(char));
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line || !buffer)
		return (NULL);
	ft_bzero(line, (ft_line_length(lst) + 1));
	ft_copy_line(lst, line, buffer);
	if (buffer[0] != '\0')
		ft_lst_add(buff, buffer, fd);
	else
		free(buffer);
	return (line);
}

void	ft_copy_line(t_list_bonus *list, char *line, char *buffer)
{
	int	i;
	int	j;

	j = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				line[j++] = list->str[i++];
				line[j] = '\0';
				j = 0;
				while (list->str[i])
					buffer[j++] = list->str[i++];
				buffer[j] = '\0';
				return ;
			}
			line[j++] = list->str[i++];
		}
		list = list->next;
	}
	line[j] = '\0';
	buffer[0] = '\0';
}

int	ft_read(t_list_bonus **lst, int fd)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	while (bytes_read)
	{
		if ((*lst) && ft_strchr((*lst)->str, '\n'))
			break ;
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (0);
		ft_bzero(buffer, (BUFFER_SIZE + 1));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			ft_lst_add(lst, buffer, fd);
			if (ft_strchr(buffer, '\n'))
				break ;
		}
		else
			free(buffer);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static t_list_bonus	*buff;
	char				*next_line;
	t_list_bonus		*lst;

	lst = NULL;
	next_line = NULL;
	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	ft_add_buffer(&buff, &lst, fd);
	ft_read(&lst, fd);
	if (lst)
	{
		next_line = ft_create_line(lst, &buff, fd);
		ft_lstfree(lst);
	}
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
	char	*line;

	int	fd1, fd2;
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