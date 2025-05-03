/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:36:11 by ainthana          #+#    #+#             */
/*   Updated: 2025/05/03 14:36:11 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	key_hit(int keycode, t_long *game)
{
	game->keyboard[keycode] = 1;
	return (0);
}

int	ft_keyboard(t_long *game)
{
	if (game->keyboard[ADVANCE])
		player_moves(1, game);
	if (game->keyboard[BACK])
		player_moves(-1, game);
	if (game->keyboard[LEFT])
		player_moves(2, game);
	if (game->keyboard[RIGHT])
		player_moves(3, game);
	if (game->keyboard[ESC] == 1 || game->keyboard[RED_BUTTON] == 1)
		exit_and_free(game);
	return (0);
}

int	close_button(t_long *game)
{
	exit_and_free(game);
	game->keyboard[79] = 1;
	return (0);
}
