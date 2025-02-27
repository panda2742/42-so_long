/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:35:39 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/27 16:28:42 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>

typedef enum e_map_tile
{
	WALL,
	FLOOR,
	PLAYER,
	COLLECTIBLE,
	END,
	FLOODED_FLOOR,
	FLOODED_PLAYER,
	FLOODED_COLLECTIBLE,
	FLOODED_END,
}	t_map_tile;

# define TILE_ID_OFFSET 5

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_img
{
	void	*ptr;
	int		w;
	int		h;
}			t_img;

typedef struct s_game
{
	t_pos	player;
	int		moves;
	int		collected;
	void	*mlx;
	void	*win;
	t_img	imgs[5];
}			t_game;

typedef struct s_sl
{
	int		status;
	size_t	width;
	size_t	height;
	size_t	sl_len;
	int		map_fd;
	int		*map;
	int		collectibles;
	int		players;
	int		ends;
	t_pos	player_pos;
	t_pos	end_pos;
	t_game	game;
}			t_sl;

# define E_FILENAME 0b1
# define E_FILEEXT 0b10
# define E_OPENFD 0b100
# define E_LINELEN 0b1000
# define E_MALLOC 0b10000
# define E_CLOSEFD 0b100000
# define E_WRONGTILE 0b1000000
# define E_WRONGARGS 0b10000000
# define E_PLAYERS 0b100000000
# define E_ENDS 0b1000000000
# define E_COLLECTIBLES 0b10000000000
# define E_DRYEND 0b100000000000
# define E_DRYCOLLECTIBLE 0b1000000000000
# define E_WALLERROR 0b10000000000000
# define E_XPMNAME 0b100000000000000
# define E_XPMEXT 0b1000000000000000
# define E_OPENXPM 0b10000000000000000
# define E_CLOSEXPM 0b100000000000000000

# define XPM_IMAGES 5

/* Parsing */
t_bool	check_file(t_sl *sl, const char *filename);
t_bool	check_lines(t_sl *sl, const char *filename);
t_bool	check_map(t_sl *sl);
t_bool	check_xpm(t_sl *sl, const char *filename);
t_bool	create_map(t_sl *sl, const char *filename);
int		init_so_long(t_sl *sl, const char *filename);

/* Rendering */
int		init_game(t_sl *sl);

/* Utils */
t_bool	try_open(t_sl *sl, const char *filename);
t_bool	try_close(t_sl *sl);
t_bool	try_open_xpm(t_sl *sl, const char *filename);
t_bool	try_close_xpm(t_sl *sl);
void	set_player(t_sl *sl, int x, int y);
void	set_end(t_sl *sl, int x, int y);
void	add_collectible(t_sl *sl, int x, int y);
char	**get_xpm(void);
int		update_status(t_sl *sl, int err);
int		error_handler(int status);
void	free_everything(t_sl *sl);
void	print_map(t_sl *sl, int x_pin, int y_pin);
char	**error_strings(void);

#endif