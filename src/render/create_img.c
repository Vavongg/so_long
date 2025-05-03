/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:36:24 by ainthana          #+#    #+#             */
/*   Updated: 2025/05/03 14:36:24 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	put_pxl(t_long *game, int x, int y, unsigned int c)
{
	char		*dest;

	if (y >= game->height || x >= game->width || x < 0 \
	|| y < 0)
		return (0);
	dest = game->pxl + game->s_line * y + x * (game->bpp / 8);
	*(unsigned int *)dest = c;
	return (0);
}

int	visible(t_long *game)
{
	render(game);
	player_position(game);
	mlx_put_image_to_window(game->mlx_ptr,
		game->mlx_win, game->img, 0, 0);
	return (0);
}
