/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:12:47 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/28 15:25:52 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_so_long(t_sl *sl, const char *filename)
{
	int	i;

	if (!check_file(sl, filename))
		return (sl->status);
	if (!check_lines(sl, filename))
		return (sl->status);
	if (!create_map(sl, filename))
		return (sl->status);
	if (!check_map(sl))
		return (sl->status);
	i = -1;
	while (++i < XPM_IMAGES)
	{
		if (!check_xpm(sl, get_xpm()[i]))
			return (sl->status);
	}
	return (sl->status);
}
