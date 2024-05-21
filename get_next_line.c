/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:29:14 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/21 16:50:15 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_closeall(void)
{
	return (-1);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*next_line;

	buffer = (char *)malloc(10 * sizeof(char));
	if (read(fd, buffer, 10))
		return (next_line);
}

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	if (fd >= 0)
		get_next_line(fd);
	return (0);
}
