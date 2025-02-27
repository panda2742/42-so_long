/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:43:19 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/27 16:30:10 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	_load_images(t_sl *sl, t_game *g);

int	init_game(t_sl *sl)
{
	t_game	g;

	g = sl->game;
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, sl->width * 64, sl->height * 64, "so_long LES SUSHIS ARRIVENT");
	_load_images(sl, &g);
	mlx_loop(g.mlx);
	return (sl->status);
}

static t_bool	_load_images(t_sl *sl, t_game *g)
{
	int	i;

	(void)sl;
	i = -1;
	while (++i < XPM_IMAGES)
	{
		g->imgs[i].ptr = mlx_xpm_file_to_image(g->mlx, get_xpm()[i], &g->imgs[i].w, &g->imgs[i].h);
		mlx_put_image_to_window(g->mlx, g->win, g->imgs[i].ptr, 64 * i, 0);
	}
	return (true);
}
