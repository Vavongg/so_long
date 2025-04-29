/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:37:55 by ainthana          #+#    #+#             */
/*   Updated: 2025/04/30 00:52:16 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*recurs(int depth, int *ret, int fd)
{
	char	buff[1];
	char	*line;
	int		files;

	files = read(fd, buff, 1);
	if (files == 0)
		buff[0] = 0;
	if (buff[0] == '\n' || buff[0] == 0)
	{
		line = malloc(sizeof(char) * depth + 1);
		if (!line)
			return (NULL);
		line[depth] = 0;
		*ret = 1;
		if (buff[0] == 0)
			*ret = 0;
		return (line);
	}
	else
	{
		line = recurs(depth + 1, ret, fd);
		line[depth] = buff[0];
	}
	return (line);
}

int	get_next_line(int fd, char **line)
{
	int	ret;

	ret = 1;
	*line = recurs(0, &ret, fd);
	return (ret);
}
