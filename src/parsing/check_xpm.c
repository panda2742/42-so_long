/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:46:55 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/27 15:09:58 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	check_xpm(t_sl *sl, const char *filename)
{
	if (!try_open(sl, filename))
		return (false);
	if (0 != ft_strncmp(&filename[ft_strlen(filename) - 4], ".xpm", 4))
		update_status(sl, E_FILEEXT);
	
	if (!try_close(sl))
		return (false);
	return (true);
}
