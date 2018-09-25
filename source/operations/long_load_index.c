/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/24 23:00:28 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
**  OKOKOKOKOKOKOKOKOKOKOKOK
**  gets two indexes, adds them and writes from the map to register with
**  third index
**  tested, seems ok
*/

void	long_load_index(t_core *core, t_fork **fork)
{
	unsigned int	codage;
	unsigned int	shift;
	unsigned int	arg[3];

	codage = find_num(core->map, (*fork)->curr_point + 1, 1);
	shift = 1;
	if (!check_codage(codage, 14))
	{
		shift += 1 + select_params_li(core, fork, codage, arg);
		if (check_regs(core, fork, codage, arg) || (arg[2] <= 0 || arg[2] > 16))
			shift = 1;
		else
			(*fork)->registr[arg[2]] = find_num(core->map,
						((*fork)->curr_point + (int)(arg[0] + arg[1]) +
						MEM_SIZE) % MEM_SIZE, 4);
	}
	make_shift(fork, shift, arg[2]);
}
