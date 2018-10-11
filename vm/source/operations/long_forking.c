/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 19:33:59 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
**  OKOKOKOKOKOKOKO copy_fork protected too
**  creates copy of curr fork and moves it to (PC + T_DIR) points
**  tested, ok
*/

void	long_forking(t_core *core, t_fork **fork)
{
	unsigned int sp;

	sp = find_num(core->map, (*fork)->curr_point + 1, 2);
	if (core->extended)
		ft_printf("%-4d||%5{grn}s||%d\n", (*fork)->curr_point, "lfork", sp);
	copy_fork(*fork, &(core->forks), (int)sp);
	make_shift(fork, 3, 0);
	core->players[find_player(core->players, (*fork)->parent_id)].nb_proc += 1;
}
