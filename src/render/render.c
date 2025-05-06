/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:31:09 by ainthana          #+#    #+#             */
/*   Updated: 2025/05/03 14:31:09 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	display(t_long *game)
{
	create_window(game);
	load_textures(game);
	load_textures2(game);
	render(game);
	write(1, "\033[32m~~ so_long launched successfully! ~~\033[00m\n", 48);
	write(1, "Moves : ", 9);
	ft_putnbr(game->move);
	player_position(game);
	go_hooking(game);
	return (0);
}

int	go_hooking(t_long *game)
{
	mlx_hook(game->mlx_win, 2, 1L, key_hit, game);
	mlx_hook(game->mlx_win, 15, 1L << 16, visible, game);
	mlx_hook(game->mlx_win, CLOSERED, 1L << 17, close_button, game);
	mlx_loop_hook(game->mlx_ptr, key_loop, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

int render(t_long *game)
{
	int x;
	int y;

	y = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			get_texture(x, y, game);
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->text[game->texture], x * 64, y * 64);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->text[3], game->player_x * 64, game->player_y * 64);
	return (0);
}

int	create_window(t_long *game)
{
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->width,
			game->height, "Kirby Nom Nom");
	return (0);
}

void handle_tile_interaction(t_long *game, char next_tile, int nx, int ny)
{
	if (next_tile == 'C')
		game->collectible++;

	if (next_tile == 'E' && game->collectible == game->collectible_total)
	{
		write(1, "\rMoves : ", 9);
		ft_putnbr(game->move + 1);
		write(1, "\nCongratulations! You finished within ", 38);
		ft_putnbr(game->move + 1);
		write(1, " moves.\n", 9);
		exit_and_free(game);
	}

	if (game->on_exit)
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';

	if (next_tile == 'E')
		game->on_exit = 1;
	else
	{
		game->map[ny][nx] = 'P';
		game->on_exit = 0;
	}
}

