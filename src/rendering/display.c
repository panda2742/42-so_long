/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:03:46 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/28 16:24:16 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves(t_sl *sl)
{
	t_game	*g;

	g = &sl->game;
	ft_putstr_fd(BLUE "You did: " RESET MAGENTA, 1);
	ft_putnbr_fd(g->moves, 1);
	ft_putstr_fd(RESET BLUE " moves!\n" RESET, 1);
}

void	display_collected_coin(t_sl *sl)
{
	t_game	*g;

	g = &sl->game;
	ft_putstr_fd(YELLOW "You ate a california roll! (" RED, 1);
	ft_putnbr_fd(g->collected, 1);
	ft_putstr_fd(RESET YELLOW "/" RESET RED, 1);
	ft_putnbr_fd(sl->collectibles, 1);
	ft_putstr_fd(RESET YELLOW ")\n" RESET, 1);
}

void	display_bye_bye(void)
{
	ft_putstr_fd(GREEN "Bye bye :)\n" RESET, 1);
}

void	display_rules(void)
{
	ft_putstr_fd(GREEN "You are the shrimp. You must eat all the", 1);
	ft_putstr_fd(" california rolls and then, go to the maki sushi.\n", 1);
	ft_putstr_fd("Rules are simple; game is ugly; what else?\n", 1);
	ft_putstr_fd("Have fun! :D\n" RESET, 1);
}
