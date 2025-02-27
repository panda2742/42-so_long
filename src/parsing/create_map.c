/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:27:21 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/27 09:51:48 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	_read_and_fill(t_sl *sl);
static void		_fill_line(t_sl *sl, char *line, int x, int y);

t_bool	create_map(t_sl *sl, const char *filename)
{
	if (!try_open(sl, filename))
		return (false);
	if (!_read_and_fill(sl))
	{
		try_close(sl);
		return (false);
	}
	if (!try_close(sl))
		return (false);
	return (true);
}

static t_bool	_read_and_fill(t_sl *sl)
{
	char	*line;
	int		x;
	int		y;

	line = get_next_line(sl->map_fd);
	if (NULL == line)
	{
		update_status(sl, E_MALLOC);
		return (false);
	}
	sl->width = ft_strlenc(line, '\n');
	sl->sl_len = sl->width * sl->height;
	sl->map = malloc(sl->sl_len * sizeof(int));
	if (NULL == sl->map)
	{
		free(line);
		update_status(sl, E_MALLOC);
		return (false);
	}
	x = 0;
	y = -1;
	_fill_line(sl, line, x, y);
	return (true);
}

static void	_fill_line(t_sl *sl, char *line, int x, int y)
{
	while (line)
	{
		++y;
		x = -1;
		while ((size_t)++x < sl->width)
		{
			if (line[x] == '1')
				sl->map[y * sl->width + x] = WALL;
			else if (line[x] == '0')
				sl->map[y * sl->width + x] = FLOOR;
			else if (line[x] == 'P')
				set_player(sl, x, y);
			else if (line[x] == 'C')
				add_collectible(sl, x, y);
			else if (line[x] == 'E')
				set_end(sl, x, y);
			else
				update_status(sl, E_WRONGTILE);
		}
		free(line);
		line = get_next_line(sl->map_fd);
	}
	free(line);
}
