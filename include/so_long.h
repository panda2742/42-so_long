/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:35:39 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/26 16:32:00 by ehosta           ###   ########.fr       */
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

typedef struct s_sl
{
	int		status;
	size_t	width;
	size_t	height;
	size_t	sl_len;
	int		map_fd;
	int		*lines;
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

#endif