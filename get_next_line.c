/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:29:14 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/22 15:38:28 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_closeall(void)
{
	return (-1);
}

char	*ft_create_line(t_list *first)
{
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*next_line;
	static int	counter;
	t_list		*new_lst;
	t_list		*first_lst;

	buffer = (char *)malloc(10 * sizeof(char));
	while (!ft_strchr(buffer, '\n'))
	{
		read(fd, buffer, 10);
		counter++;
		new_lst = ft_lstnew(buffer);
		if (counter == 1)
			first_lst = new_lst;
		else
			ft_lstadd_back(first_lst, new_lst);
	}
	next_line = ft_create_line(first_lst);
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
			get_next_line(fd);
		close(argv[1]);
	}
	return (0);
}
