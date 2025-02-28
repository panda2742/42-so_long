/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:43:19 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/28 12:17:06 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_sl *sl)
{
	t_game	*g;
	int		i;

	g = &sl->game;
	g->player.x = sl->player_pos.x;
	g->player.y = sl->player_pos.y;
	g->mlx = mlx_init();
	g->win = mlx_new_window(
			g->mlx,
			sl->width * 64,
			sl->height * 64,
			"so_long - SUSHIS, MANGEZ-LES TOUS !");
	i = -1;
	while (++i < XPM_IMAGES)
		g->imgs[i].ptr = mlx_xpm_file_to_image(
				g->mlx, get_xpm()[i], &g->imgs[i].w, &g->imgs[i].h);
	render_map(sl);
	game_hooks(sl);
	mlx_loop(g->mlx);
	return (sl->status);
}
