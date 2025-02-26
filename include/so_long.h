/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:35:39 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/26 18:42:14 by ehosta           ###   ########.fr       */
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

typedef struct s_sl
{
	int		status;
	size_t	width;
	size_t	height;
	size_t	sl_len;
	int		map_fd;
	int		*line;
	int		collectibles;
	int		players;
	int		ends;
	t_pos	player_pos;
	t_pos	end_pos;
}			t_sl;

typedef struct s_sl_parsing
{
	t_bool	player_placed;
	t_bool	valid_walls;
}			t_sl_parsing;

# define E_FILENAME 0b1
# define E_FILEEXT 0b10
# define E_OPENFD 0b100
# define E_LINELEN 0b1000
# define E_MALLOC 0b10000
# define E_CLOSEFD 0b100000
# define E_WRONGTILE 0b1000000
# define E_WRONGARGS 0b10000000

int		update_status(t_sl *sl, int err);
int		error_handler(int status);
void	free_everything(t_sl *sl);
int		parse_map(t_sl *sl, const char *filename);
t_bool	init_parsing(t_sl *sl, const char *filename);
t_bool	create_line(t_sl *sl, const char *filename);

t_bool	try_open(t_sl *sl, const char *filename);
t_bool	try_close(t_sl *sl);

void	set_player(t_sl *sl, int x, int y);
void	set_end(t_sl *sl, int x, int y);
void	add_collectible(t_sl *sl, int x, int y);

#endif