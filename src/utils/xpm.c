/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:05:18 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/27 16:24:48 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_xpm(void)
{
	static char	*images[XPM_IMAGES] = {
		"assets/xpm/sushi1.xpm",
		"assets/xpm/sushi2.xpm",
		"assets/xpm/shrimp.xpm",
		"assets/xpm/wall.xpm",
		"assets/xpm/floor.xpm",
	};

	return (images);
}

t_bool	try_open_xpm(t_sl *sl, const char *filename)
{
	if (NULL == filename || 0 == filename[0])
	{
		update_status(sl, E_XPMNAME);
		return (false);
	}
	sl->map_fd = open(filename, O_RDONLY);
	if (sl->map_fd < 0)
	{
		update_status(sl, E_OPENXPM);
		return (false);
	}
	return (true);
}

t_bool	try_close_xpm(t_sl *sl)
{
	if (close(sl->map_fd) < 0)
	{
		update_status(sl, E_CLOSEXPM);
		return (false);
	}
	return (true);
}
