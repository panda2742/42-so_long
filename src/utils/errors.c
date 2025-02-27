/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:01:44 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/27 16:17:46 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**error_strings(void)
{
	static char	*errors[18] = {
		" [E_FILENAME]       Filename error.\n",
		" [E_FILEEXT]        File extension error.\n",
		" [E_OPENFD]         Error while opening map.\n",
		" [E_LINELEN]        The map is not a rectangle.\n",
		" [E_MALLOC]         A heap memory allocation failed.\n",
		" [E_CLOSEFD]        Error while closing map.\n",
		" [E_WRONGTILE]      An invalid character is present.\n",
		" [E_WRONGARGS]      Only one argument (a map) is valid.\n",
		" [E_PLAYERS]        Only one player is expected.\n",
		" [E_ENDS]           Only one end is expected.\n",
		" [E_COLLECTIBLES]   Map musts have collectibles.\n",
		" [E_DRYEND]         The end is not reachable.\n",
		" [E_DRYCOLLECTIBLE] Some collectibles are not reachable.\n",
		" [E_WALLERROR]      Map is not enclosed with walls.\n",
		" [E_XPMNAME]        Error with XPM filename.\n",
		" [E_XPMEXT]         Error with XPM file extension.\n",
		" [E_OPENXPM]        Error while opening XPM file.\n",
		" [E_CLOSEXPM]       Error while closing XPM file.\n"
	};

	return (errors);
}
