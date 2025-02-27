/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:47:00 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/27 12:03:17 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	_check_values(t_sl *sl);
static void	_flood_map_and_check(t_sl *sl);
static void	_flood_tile(t_sl *sl, int x, int y);
static void	_check_walls(t_sl *sl);

t_bool	check_map(t_sl *sl)
{
	_check_values(sl);
	_flood_map_and_check(sl);
	_check_walls(sl);
	return (0 == sl->status);
}

static void	_check_values(t_sl *sl)
{
	if (1 != sl->players)
		update_status(sl, E_PLAYERS);
	if (1 != sl->ends)
		update_status(sl, E_ENDS);
	if (0 == sl->collectibles)
		update_status(sl, E_COLLECTIBLES);
}

static void	_flood_map_and_check(t_sl *sl)
{
	t_map_tile	tile;
	size_t		i;

	_flood_tile(sl, sl->player_pos.x, sl->player_pos.y);
	i = -1;
	while (++i < sl->sl_len)
	{
		tile = sl->map[i];
		if (WALL == tile || tile >= TILE_ID_OFFSET)
			continue ;
		if (END == tile)
			update_status(sl, E_DRYEND);
		if (COLLECTIBLE == tile)
			update_status(sl, E_DRYCOLLECTIBLE);
	}
}

static void	_flood_tile(t_sl *sl, int x, int y)
{
	const t_map_tile	tile = sl->map[y * sl->width + x];

	if (WALL == tile || tile >= TILE_ID_OFFSET)
		return ;
	sl->map[y * sl->width + x] = tile + TILE_ID_OFFSET;
	_flood_tile(sl, x + 1, y);
	_flood_tile(sl, x - 1, y);
	_flood_tile(sl, x, y + 1);
	_flood_tile(sl, x, y - 1);
}

static void	_check_walls(t_sl *sl)
{
	t_map_tile	tile;
	size_t		x;
	size_t		y;

	y = -1;
	while (++y < sl->height)
	{
		x = -1;
		while (++x < sl->width)
		{
			tile = sl->map[y * sl->width + x];
			if ((0 == x || sl->width - 1 == x) && WALL != tile)
			{
				update_status(sl, E_WALLERROR);
				break ;
			}
			if ((0 == y || sl->height - 1 == y) && WALL != tile)
			{
				update_status(sl, E_WALLERROR);
				break ;
			}
		}
	}
}
