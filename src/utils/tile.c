/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:11:30 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/27 09:27:49 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player(t_sl *sl, int x, int y)
{
	sl->map[y * sl->width + x] = PLAYER;
	sl->player_pos.x = x;
	sl->player_pos.y = y;
	sl->players++;
}

void	set_end(t_sl *sl, int x, int y)
{
	sl->map[y * sl->width + x] = END;
	sl->end_pos.x = x;
	sl->end_pos.y = y;
	sl->ends++;
}

void	add_collectible(t_sl *sl, int x, int y)
{
	sl->map[y * sl->width + x] = COLLECTIBLE;
	sl->collectibles++;
}
