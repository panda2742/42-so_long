/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:34:03 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/28 13:20:06 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_sl *sl)
{
	t_game		*g;
	size_t		i;
	int			col;
	t_map_tile	tile;

	g = &sl->game;
	i = -1;
	ft_printf("p: %d %d\n", g->player.x, g->player.y);
	while (++i < sl->sl_len)
	{
		col = i / sl->width;
		tile = sl->map[i];
		if (WALL == tile)
			mlx_put_image_to_window(g->mlx, g->win, g->imgs[WALL_XPM].ptr, (i - col * sl->width) * 64, col * 64);
		else if (FLOODED_FLOOR == tile || FLOODED_PLAYER == tile)
			mlx_put_image_to_window(g->mlx, g->win, g->imgs[FLOOR_XPM].ptr, (i - col * sl->width) * 64, col * 64);
		else if (FLOODED_END == tile)
			mlx_put_image_to_window(g->mlx, g->win, g->imgs[END_XPM].ptr, (i - col * sl->width) * 64, col * 64);
		else if (FLOODED_COLLECTIBLE == tile)
			mlx_put_image_to_window(g->mlx, g->win, g->imgs[COLLECTIBLE_XPM].ptr, (i - col * sl->width) * 64, col * 64);
		if (g->player.x == (int)(i - col * sl->width) && g->player.y == col)
			mlx_put_image_to_window(g->mlx, g->win, g->imgs[PLAYER_XPM].ptr, (i - col * sl->width) * 64, col * 64);
	}
}
