/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:34:45 by ainthana          #+#    #+#             */
/*   Updated: 2025/04/30 00:50:58 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_long
{
	int	x;
	int	y;
}	t_long;

//main
int		main(int ac, char **av);

//get_next_line
char	*recurs(int depth, int *ret, int fd);
int		get_next_line(int fd, char **line);

//parsing
int	check_file(char *str, t_long *game);




#endif
