/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:00:10 by ainthana          #+#    #+#             */
/*   Updated: 2025/05/03 15:45:14 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_long	so_long;

	variables_init(&so_long);
	if (ac == 1)
		error_msg(&so_long, "Type a map to open");
	if (ac > 2)
		error_msg(&so_long, "Invalid arguments (too many)");
	parsing(&so_long, av[1]);
	display(&so_long);
	return (0);
}
