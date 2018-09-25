/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/24 22:37:56 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
**  OKOKOKOKOKOKOKOK
** reads three indexes and substract values from registers with first and
** second indexes into register with third index
** tested ok
*/

void	substract(t_core *core, t_fork **fork)
{
	unsigned int	arg[3];
	unsigned int	shift;
	unsigned int	codage;

	codage = find_num(core->map, (*fork)->curr_point + 1, 1);
	arg[0] = find_num(core->map, (*fork)->curr_point + 2, 1);
	arg[1] = find_num(core->map, (*fork)->curr_point + 3, 1);
	arg[2] = find_num(core->map, (*fork)->curr_point + 4, 1);
	shift = 1;
	if (!check_codage(codage, 4) && ((arg[0] > 0 && arg[0] < 17) &&
				(arg[1] > 0 && arg[1] < 17) && (arg[2] > 0 && arg[2] < 17)))
	{
		(*fork)->registr[arg[2]] = (*fork)->registr[arg[0]] -
			(*fork)->registr[arg[1]];
		shift = 5;
	}
	make_shift(fork, shift, arg[2]);
}
