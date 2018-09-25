/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/24 22:17:37 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
**	takes three params, first and second can be or reg or dir or ind,
**  and makes & with first and second values into registr wtih third index
**  need more tests, seems ok
*/

void	anding(t_core *core, t_fork **fork)
{
	unsigned int	shift;
	unsigned int	codage;
	unsigned int	arg[3];

	shift = 1;
	codage = find_num(core->map, (*fork)->curr_point + 1, 1);
	if (!check_codage(codage, 6))
	{
		shift += 1 + select_params(core, fork, codage, arg);
		if (check_regs(core, fork, codage, arg) || arg[2] <= 0 || arg[2] > 16)
			shift = 1;
		else
			(*fork)->registr[arg[2]] = arg[0] & arg[1];
	}
	make_shift(fork, shift, arg[2]);
}
