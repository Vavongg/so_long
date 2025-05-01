/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:43:47 by ainthana          #+#    #+#             */
/*   Updated: 2025/05/01 17:43:47 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	parsing(t_long *game, char *av)
{
	check_file(av, game);
	get_position(game, av);
	malloc_map(game);
	load_map(game, av);
	check_map(game);
	return (0);
}

int	get_position(t_long *game, char *filename)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(filename, O_RDONLY);
	ret = get_next_line(fd, &line);
	game->oldx = ft_strlen(line);
	while (line[is_whitespace(line)] == '1' || line[is_whitespace(line)] == '0')
	{
		game->x = ft_strlen(line);
		if (game->x != game->oldx)
			error_msg(game, "Invalid map: must be rectangular");
		game->oldx = game->x;
		if (ret != -1)
			free(line);
		ret = get_next_line(fd, &line);
		game->y++;
	}
	if (game->y == 0 || game->x == 0)
		error_msg(game, "Invalid map");
	game->height = game->y * 64;
	free(line);
	game->width = game->x * 64;
	close(fd);
	return (0);
}

char	replace_char(char c)
{
	if (c == '0')
		return ('a');
	if (c == '1')
		return ('1');
	if (c == 'P')
		return ('c');
	if (c == 'E')
		return ('d');
	if (c == 'C')
		return ('e');
	return (0);
}

int	variables_init(t_long *game)
{
	game->keyboard[BACK] = 0;
	game->keyboard[RED_BUTTON] = 0;
	game->keyboard[ESC] = 0;
	game->keyboard[LEFT] = 0;
	game->keyboard[RIGHT] = 0;
	game->keyboard[ADVANCE] = 0;
	game->bpp = 0;
	game->casein = 0;
	game->casetotal = 0;
	game->y = 0;
	game->x = 0;
	game->collectible = 0;
	game->collectible_total = 0;
	game->s_line = 0;
	game->maptofree = -1;
	game->move = 0;
	game->playerset = 0;
	game->collectibleset = 0;
	game->exitset = 0;
	game->lastplayer_x = -1;
	game->lastplayer_y = -1;
	game->mlx_ptr = NULL;
	return (0);
}