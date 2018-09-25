/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/24 22:16:24 by dskrypny         ###   ########.fr       */
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
	copy_fork(*fork, &(core->forks), (int)sp);
	make_shift(fork, 3, 0);
}
