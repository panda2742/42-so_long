/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:13:37 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/26 18:45:16 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_status(t_sl *sl, int err)
{
	sl->status |= err;
	return (sl->status);
}

int	error_handler(int status)
{
	static char	*errors[8] = {
		" [-] Filename error.\n",
		" [-] File extension error.\n",
		" [-] Error while opening map.\n",
		" [-] The map is not a rectangle.\n",
		" [-] A heap memory allocation failed.\n",
		" [-] Error while closing map.\n",
		" [-] An invalid character is present.\n",
		" [-] Only one argument (a map) is valid.\n"
	};
	const int	bits = sizeof(status) * 8;
	int			i;

	if (0 == status)
		return (EXIT_SUCCESS);
	ft_eprintf(RED "Error\n  |  Code %d:\n", status);
	i = -1;
	while (++i < bits)
	{
		if (status & (1 << i))
			ft_eprintf(errors[i]);
	}
	ft_eprintf(RESET);
	return (EXIT_FAILURE);
}

void	free_everything(t_sl *sl)
{
	if (sl->line)
		free(sl->line);
}
