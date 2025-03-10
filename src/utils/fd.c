/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:36:47 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/27 09:53:01 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	try_open(t_sl *sl, const char *filename)
{
	if (NULL == filename || 0 == filename[0])
	{
		update_status(sl, E_FILENAME);
		return (false);
	}
	sl->map_fd = open(filename, O_RDONLY);
	if (sl->map_fd < 0)
	{
		update_status(sl, E_OPENFD);
		return (false);
	}
	return (true);
}

t_bool	try_close(t_sl *sl)
{
	if (close(sl->map_fd) < 0)
	{
		update_status(sl, E_CLOSEFD);
		return (false);
	}
	return (true);
}
