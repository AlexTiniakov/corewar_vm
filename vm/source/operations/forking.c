/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 16:31:06 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
** OKOKOKOKOKOKOKOKOKO
** creates copy of curr fork and moves it to (PC + T_DIR % IDX_MOD) points
** tested, ok
*/

static void	extended_fork(t_fork *fork, int arg)
{
	ft_printf("%-4d||%5{grn}s||%d\n", fork->curr_point, "fork", arg);
}

void		forking(t_core *core, t_fork **fork)
{
	unsigned int sp;

	sp = find_num(core->map, (*fork)->curr_point + 1, 2);
	if (core->extended)
		extended_fork(*fork, (int)sp);
	copy_fork(*fork, &(core->forks), ((int)sp % IDX_MOD + MEM_SIZE)
			% MEM_SIZE);
	core->players[find_player(core->players, (*fork)->parent_id)].nb_proc += 1;
	make_shift(fork, 3, 0);
}
