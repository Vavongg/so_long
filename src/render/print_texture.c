/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:32:09 by ainthana          #+#    #+#             */
/*   Updated: 2025/05/03 14:32:09 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	load_textures(t_long *game)
{
	game->text[0] = mlx_xpm_file_to_image(game->mlx_ptr, \
					"./src/images/grass.xpm",
			&game->widthtext[0], &game->heighttext[0]);
	game->ptr_text[0] = mlx_get_data_addr(game->text[0],
			&(game->bpp_text[0]), &(game->sline_text[0]), &(game->ed_text[0]));
	game->text[1] = mlx_xpm_file_to_image(game->mlx_ptr, \
					"./src/images/wall.xpm",
			&game->widthtext[1], &game->heighttext[1]);
	game->ptr_text[1] = mlx_get_data_addr(game->text[1],
			&(game->bpp_text[1]), &(game->sline_text[1]), &(game->ed_text[1]));
	game->text[3] = mlx_xpm_file_to_image(game->mlx_ptr, \
					"./src/images/kirby.xpm",
			&game->widthtext[3], &game->heighttext[3]);
	return (0);
}

int	load_textures2(t_long *game)
{
	game->ptr_text[3] = mlx_get_data_addr(game->text[3],
			&(game->bpp_text[3]), &(game->sline_text[3]), &(game->ed_text[3]));
	game->text[2] = mlx_xpm_file_to_image(game->mlx_ptr, \
					"./src/images/star.xpm",
			&game->widthtext[2], &game->heighttext[2]);
	game->ptr_text[2] = mlx_get_data_addr(game->text[2],
			&(game->bpp_text[2]), &(game->sline_text[2]), &(game->ed_text[2]));
	game->text[4] = mlx_xpm_file_to_image(game->mlx_ptr, \
					"./src/images/exit.xpm",
			&game->widthtext[4], &game->heighttext[4]);
	game->ptr_text[4] = mlx_get_data_addr(game->text[4],
			&(game->bpp_text[4]), &(game->sline_text[4]), &(game->ed_text[4]));
	return (0);
}

int print_texture(t_long *game, int starter_X, int starter_Y)
{
    mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->text[game->texture], starter_X * 64, starter_Y * 64);
    return (0);
}


int	get_texture(int X, int Y, t_long *game)
{
	if (game->map[Y][X] == '0' || game->map[Y][X] == 'a')
		game->texture = 0;
	if (game->map[Y][X] == '1')
		game->texture = 1;
	if (game->map[Y][X] == 'C')
		game->texture = 2;
	if (game->map[Y][X] == 'E')
		game->texture = 4;
	if (game->map[Y][X] == 'P')
		game->texture = 3;
	return (0);
}
int visible(int keycode, t_long *game)
{
    (void)keycode;
    (void)game;
    return (0);
}


