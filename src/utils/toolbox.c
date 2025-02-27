/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:13:37 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/27 11:39:19 by ehosta           ###   ########.fr       */
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
	const int	bits = sizeof(status) * 8;
	int			i;

	if (0 == status)
		return (EXIT_SUCCESS);
	ft_eprintf(RED "Error\n  |  Code %d:\n", status);
	i = -1;
	while (++i < bits)
	{
		if (status & (1 << i))
			ft_eprintf(error_strings()[i]);
	}
	ft_eprintf(RESET);
	return (EXIT_FAILURE);
}

void	free_everything(t_sl *sl)
{
	if (sl->map)
		free(sl->map);
}

void	print_map(t_sl *sl, int x_pin, int y_pin)
{
	int		x;
	size_t	y;

	y = 0;
	while (y < sl->height)
	{
		x = -1;
		while ((size_t)++x < sl->width)
		{
			if (x == x_pin && (int)y == y_pin)
				ft_putstr_fd(RED, 1);
			else if (sl->map[y * sl->width + x] >= TILE_ID_OFFSET)
				ft_putstr_fd(BLUE, 1);
			else if (sl->map[y * sl->width + x] == WALL)
				ft_putstr_fd(CYAN, 1);
			else
				ft_putstr_fd(MAGENTA, 1);
			ft_putchar_fd(sl->map[y * sl->width + x] + '0', 1);
			ft_putchar_fd(' ', 1);
			ft_putstr_fd(RESET, 1);
		}
		ft_putchar_fd('\n', 1);
		y++;
	}
}
