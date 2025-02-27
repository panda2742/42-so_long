/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:22:19 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/27 11:22:23 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	check_file(t_sl *sl, const char *filename)
{
	if (!try_open(sl, filename))
		return (false);
	if (0 != ft_strncmp(&filename[ft_strlen(filename) - 4], ".ber", 4))
		update_status(sl, E_FILEEXT);
	if (!try_close(sl))
		return (false);
	return (true);
}
