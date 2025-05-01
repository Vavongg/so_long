/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:34:45 by ainthana          #+#    #+#             */
/*   Updated: 2025/05/01 18:37:53 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define ADVANCE 119
# define BACK 115
# define RIGHT 100
# define LEFT 97
# define ESC 65307
# define RED_BUTTON 79
# define CLOSERED 33

typedef struct s_long
{
	char			**map;
	int				width;
	int				height;
	int				x;
	int				y;
	int				oldx;
	int				collectibles_found;
	int				exits_found;
	int				player_x;
	int				player_y;
	int				lastplayer_x;
	int				lastplayer_y;
	int				collectible;
	int				collectible_total;
	int				move;
	int				playerset;
	int				exitset;
	int				collectibleset;

	char			*pxl;
	int				bpp;
	int				s_line;
	double			casetotal;
	double			casein;
	int				ed;
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				keyboard[70000];
	int				maptofree;

	int				bpp_text[10];
	int				sline_text[10];
	int				ed_text[10];
	char			*ptr_text[10];
	void			*text[10];
	int				widthtext[10];
	int				heighttext[10];
	int				texture;
	unsigned int	color;
}					t_long;

//main
int		main(int ac, char **av);

//parsing
int		check_file(char *str, t_long *game);
int		floodandfill(t_long *game, int mapy, int mapx);
int		check_walls(int mapx, int mapy, t_long *game);
int		check_walls2(t_long *game);
int		load_map(t_long *game, char *filename);
int		stock_line(t_long *game, char *line, int nb);
int		check_map(t_long *game);
int		malloc_map(t_long *game);
int		checkifgood(char c);
int		variables_init(t_long *game);
int		get_position(t_long *game, char *filename);
int		parsing(t_long *game, char *av);
void	floodandfill2(t_long *game, int mapy, int mapx);
char	replace_char(char c);

//utils
char	*recurs(int depth, int *ret, int fd);
int		get_next_line(int fd, char **line);
void	ft_putchar(char c);
char	*ft_strcpy(char *dest, char *src);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
size_t	ft_strlen(const char *s);
char	*recurs(int depth, int *ret, int fd);
int		free_map(t_long *game);
int		exit_and_free(t_long *game);
int		error_msg(t_long *game, char *str);
int		get_next_line(int fd, char **line);
int		is_whitespace(char *str);

#endif
