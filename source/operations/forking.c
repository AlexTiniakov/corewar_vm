/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/24 20:27:27 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
** OKOKOKOKOKOKOKOKOKO
** creates copy of curr fork and moves it to (PC + T_DIR % IDX_MOD) points
** tested, ok
*/

void	forking(t_core *core, t_fork **fork)
{
	unsigned int sp;

	sp = find_num(core->map, (*fork)->curr_point + 1, 2);
	copy_fork(*fork, &(core->forks), ((int)sp % IDX_MOD + MEM_SIZE)
			% MEM_SIZE);
	make_shift(fork, 3, 0);
}
