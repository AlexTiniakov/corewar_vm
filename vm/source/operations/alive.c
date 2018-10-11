/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 20:24:28 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
** checks player and says it's alive
** tested, ok
*/

static void	extended_alive(t_fork *fork, int arg)
{
	ft_printf("%-4d||%5{grn}s||%d\n", fork->curr_point, "live", arg);
}

void		alive(t_core *core, t_fork **fork)
{
	unsigned int	reg;
	int				pl_index;

	reg = find_num(core->map, (*fork)->curr_point + 1, 4);
	if (core->extended)
		extended_alive(*fork, reg);
	(*fork)->alive = 1;
	(*fork)->live_num += 1;
	if ((pl_index = find_player(core->players, reg)) >= 0)
	{
		core->players[pl_index].alive = 1;
		core->players[pl_index].live_num += 1;
		core->players[pl_index].last_live = core->cycles_num + 1;
		core->players[pl_index].hole_game_live_num += 1;
		if (core->extended)
			ft_printf("A process shows that player %d (%s)%s", reg,
				core->players[pl_index].prog_name, " is alive!\n");
		core->players_live += 1;
	}
	make_shift(fork, 5, 0);
}
