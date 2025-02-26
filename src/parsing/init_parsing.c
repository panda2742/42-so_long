/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:22:19 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/26 18:38:34 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	_read_lines(t_sl *sl);

t_bool	init_parsing(t_sl *sl, const char *filename)
{
	if (!try_open(sl, filename))
		return (false);
	if (!_read_lines(sl))
		return (false);
	if (!try_close(sl))
		return (false);
	return (true);
}

static t_bool	_read_lines(t_sl *sl)
{
	char	*line;

	line = get_next_line(sl->map_fd);
	if (NULL == line)
		return (update_status(sl, E_MALLOC));
	sl->height = 0;
	sl->width = ft_strlenc(line, '\n');
	while (line)
	{
		if (ft_strlenc(line, '\n') != sl->width)
		{
			free(line);
			update_status(sl, E_LINELEN);
			return (false);
		}
		free(line);
		line = get_next_line(sl->map_fd);
		sl->height++;
	}
	free(line);
	return (true);
}
