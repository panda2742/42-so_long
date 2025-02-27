/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:46:55 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/27 16:16:54 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	check_xpm(t_sl *sl, const char *filename)
{
	if (!try_open_xpm(sl, filename))
		return (false);
	if (0 != ft_strncmp(&filename[ft_strlen(filename) - 4], ".xpm", 4))
		update_status(sl, E_XPMEXT);
	if (!try_close_xpm(sl))
		return (false);
	return (true);
}
