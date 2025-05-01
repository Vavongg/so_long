/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:43:23 by ainthana          #+#    #+#             */
/*   Updated: 2025/05/01 17:43:23 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	load_map(t_long *game, char *filename)
{
	char	*line;
	int		fd;
	int		ret;
	int		nb;

	nb = 0;
	fd = open(filename, O_RDONLY);
	ret = get_next_line(fd, &line);
	while (line[is_whitespace(line)] == '1' || line[is_whitespace(line)] == '0')
	{
		stock_line(game, line, nb);
		if (ret != -1)
			free(line);
		ret = get_next_line(fd, &line);
		nb++;
	}
	free(line);
	return (0);
}

int	stock_line(t_long *game, char *line, int nb)
{
	int	index;

	index = 0;
	while (line[index])
	{
		game->casetotal++;
		game->map[nb][index] = replace_char(line[index]);
		if (line[index] == 'P')
		{
			game->playerset++;
			game->player_x = index;
			game->player_y = nb;
		}
		if (line[index] == 'E')
			game->exitset++;
		if (line[index] == 'C')
			game->collectible_total++;
		if (line[index] != 'P' && line[index] != 'E' && line[index]
			!= 'C' && line[index] != '1' && line[index] != '0')
			error_msg(game, "Invalid characters, go check map");
		index++;
	}
	return (0);
}

int	check_map(t_long *game)
{
	if (game->playerset < 1)
		error_msg(game, "Missing player");
	if (game->playerset > 1)
		error_msg(game, "SOLO LEVELING ON A DIT");
	if (game->exitset < 1)
		error_msg(game, "No exit found");
	if (game->exitset > 1)
		error_msg(game, "More than one exit found");
	if (game->collectible_total == 0)
		error_msg(game, "No collectible found");
	check_walls2(game);
	return (0);
}

int	malloc_map(t_long *game)
{
	int	i;

	i = 0;
	game->map = malloc(sizeof(char *) * game->y);
	while (i < game->y)
	{
		game->map[i] = malloc(sizeof(char) * (game->x + 1));
		i++;
	}
	game->maptofree = 1;
	return (1);
}

int	checkifgood(char c)
{
	if (c != '0' && c != 'a' && c != '1' && c != 'P' && c != 'c' && c != 'E'
		&& c != 'd' && c != 'C' && c != 'e')
		return (0);
	return (1);
}