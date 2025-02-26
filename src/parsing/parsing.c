/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:12:47 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/26 18:38:31 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_map(t_sl *sl, const char *filename)
{
	if (!init_parsing(sl, filename))
		return (sl->status);
	if (!create_line(sl, filename))
		return (sl->status);
	return (sl->status);
}
