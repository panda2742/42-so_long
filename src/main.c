/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:14:40 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/26 18:46:06 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	_init(int argc, char **argv, t_sl *sl);

int	main(int argc, char **argv)
{
	t_sl	sl;

	_init(argc, argv, &sl);
	free_everything(&sl);
	return (error_handler(sl.status));
}

static t_bool	_init(int argc, char **argv, t_sl *sl)
{
	sl->status = 0b0;
	if (2 != argc)
	{
		update_status(sl, E_WRONGARGS);
		return (false);
	}
	sl->height = 0;
	sl->map_fd = -1;
	sl->height = 0;
	sl->sl_len = 0;
	sl->line = NULL;
	sl->player_pos.x = -1;
	sl->player_pos.y = -1;
	sl->players = 0;
	sl->end_pos.x = -1;
	sl->end_pos.y = -1;
	sl->ends = 0;
	sl->collectibles = 0;
	parse_map(sl, argv[1]);
	return (0 == sl->status);
}
