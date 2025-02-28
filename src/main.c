/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:14:40 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/28 15:47:44 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	_start(int argc, char **argv, t_sl *sl);
static void	_init_sl_vars(t_sl *sl);

int	main(int argc, char **argv)
{
	t_sl	sl;

	_start(argc, argv, &sl);
	if (!sl.status)
		init_game(&sl);
	free_everything(&sl);
	return (error_handler(sl.status));
}

static void	_start(int argc, char **argv, t_sl *sl)
{
	_init_sl_vars(sl);
	if (2 != argc)
	{
		update_status(sl, E_WRONGARGS);
		return ;
	}
	if (0 != init_so_long(sl, argv[1]))
		return ;
}

static void	_init_sl_vars(t_sl *sl)
{
	sl->status = 0b0;
	sl->width = 0;
	sl->height = 0;
	sl->sl_len = 0;
	sl->map_fd = -1;
	sl->map = NULL;
	sl->collectibles = 0;
	sl->players = 0;
	sl->ends = 0;
	sl->player_pos.x = -1;
	sl->player_pos.y = -1;
	sl->end_pos.x = -1;
	sl->end_pos.y = -1;
	sl->game.collected = 0;
	sl->game.moves = 0;
	sl->game.player.x = 0;
	sl->game.player.y = 0;
	sl->game.mlx = NULL;
	sl->game.win = NULL;
}
