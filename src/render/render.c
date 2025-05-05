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
	mlx_put_image_to_window(game->mlx_ptr,
		game->mlx_win, game->img, 0, 0);
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

int	key_loop(t_long *game)
{
	ft_keyboard(game);
	if (game->keyboard[ESC] == 1 || game->keyboard[RIGHT] == 1
		|| game->keyboard[LEFT] == 1 || game->keyboard[BACK] == 1
		|| game->keyboard[ADVANCE] == 1)
	{
		player_position(game);
		mlx_put_image_to_window(game->mlx_ptr,
			game->mlx_win, game->img, 0, 0);
	}
	return (0);
}

int	render(t_long *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < game->y)
	{
		while (x < game->x)
		{
			game->casein++;
			get_texture(x, y, game);
			print_texture(game, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	create_window(t_long *game)
{
	game->mlx_ptr = mlx_init();
	game->img = mlx_new_image(game->mlx_ptr, game->width, game->height);
	game->pxl = mlx_get_data_addr(game->img,
			&(game->bpp), &(game->s_line),
			&(game->ed));
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->width,
			game->height, "Kirby Nom Nom");
	return (0);
}
