/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:34:16 by ainthana          #+#    #+#             */
/*   Updated: 2025/05/03 14:34:16 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int player_moves(int nb, t_long *game)
{
    if (nb == 1)
    {
        if (game->map[game->player_y - 1][game->player_x] != '1')
            show_moves(game, nb);
    }
    else if (nb == -1)
    {
        if (game->map[game->player_y + 1][game->player_x] != '1')
            show_moves(game, nb);
    }
    else if (nb == 2)
    {
        if (game->map[game->player_y][game->player_x - 1] != '1')
            show_moves(game, nb);
    }
    else if (nb == 3)
    {
        if (game->map[game->player_y][game->player_x + 1] != '1')
            show_moves(game, nb);
    }
    return (0);
}

int show_moves(t_long *game, int nb)
{
	int nx = game->player_x + (nb == 3) - (nb == 2);
	int ny = game->player_y + (nb == -1) - (nb == 1);
	char next_tile = game->map[ny][nx];

	if (next_tile == '1')
		return (0);

	handle_tile_interaction(game, next_tile, nx, ny);

	game->player_x = nx;
	game->player_y = ny;

	game->move++;
	write(1, "\rMoves : ", 9);
	ft_putnbr(game->move);

	render(game);
	return (0);
}

int	final_moves(t_long *game)
{
	if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->collectible++;
		game->map[game->player_y][game->player_x] = '0';
	}
	if (game->map[game->player_y][game->player_x] == 'E')
	{
		if (game->collectible == game->collectible_total)
		{
			write(1, "\b\b\b\b\b\b\b\b\b\b", 11);
			write(1, "Congratulations! You finished within ", 37);
			ft_putnbr(game->move);
			write(1, " moves.\n", 9);
			exit_and_free(game);
		}
	}
	return (0);
}

int	player_position(t_long *game)
{
	if (game->lastplayer_x != -1)
	{
		get_texture(game->lastplayer_x, game->lastplayer_y, game);
		print_texture(game, game->lastplayer_x, game->lastplayer_y);
	}
	get_texture(game->player_x, game->player_y, game);
	print_texture(game, game->player_x, game->player_y);
	game->texture = 3;
	print_texture(game, game->player_x, game->player_y);
	game->lastplayer_x = game->player_x;
	game->lastplayer_y = game->player_y;
	reset_keyboard(game);
	return (0);
}

void	reset_keyboard(t_long *game)
{
	game->keyboard[ESC] = 0;
	game->keyboard[RIGHT] = 0;
	game->keyboard[LEFT] = 0;
	game->keyboard[BACK] = 0;
	game->keyboard[ADVANCE] = 0;
}
