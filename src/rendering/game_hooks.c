/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:20:18 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/28 16:24:30 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	_valid_access(t_sl *sl, int x, int y);
static t_bool	_handle_collect(t_sl *sl, int *x, int *y);

int	key_press(int keycode, t_sl *sl)
{
	int	*x;
	int	*y;

	x = &sl->game.player.x;
	y = &sl->game.player.y;
	if (keycode == 65307)
	{
		free_everything(sl);
		return (0);
	}
	if (keycode == 'w' && _valid_access(sl, *x, *y - 1))
		*y -= 1;
	if (keycode == 'a' && _valid_access(sl, *x - 1, *y))
		*x -= 1;
	if (keycode == 's' && _valid_access(sl, *x, *y + 1))
		*y += 1;
	if (keycode == 'd' && _valid_access(sl, *x + 1, *y))
		*x += 1;
	render_map(sl);
	if (_handle_collect(sl, x, y))
		free_everything(sl);
	return (0);
}

int	destroy_press(t_sl *sl)
{
	free_everything(sl);
	return (0);
}

void	game_hooks(t_sl *sl)
{
	t_game	*g;

	g = &sl->game;
	mlx_hook(g->win, 2, 1L << 0, key_press, sl);
	mlx_hook(g->win, 17, 1L << 0, destroy_press, sl);
}

static t_bool	_valid_access(t_sl *sl, int x, int y)
{
	if (x < 0 || y < 0)
		return (false);
	if (sl->map[y * sl->width + x] == WALL)
		return (false);
	sl->game.moves++;
	display_moves(sl);
	return (true);
}

static t_bool	_handle_collect(t_sl *sl, int *x, int *y)
{
	if (sl->map[*y * sl->width + *x] == FLOODED_COLLECTIBLE)
	{
		sl->game.collected++;
		sl->map[*y * sl->width + *x] = FLOODED_FLOOR;
		display_collected_coin(sl);
	}
	if (sl->map[*y * sl->width + *x] == FLOODED_END
		&& sl->game.collected == sl->collectibles)
		return (true);
	return (false);
}
