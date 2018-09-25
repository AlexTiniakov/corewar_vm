/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/24 21:52:02 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
**  OKOKOKOKOKOKOKOK
**  gets two indexes, adds them and writes from the map to register with
**  third index
**  tested, seems ok
*/

int			select_params_li(t_core *core, t_fork **fork, unsigned int codage,
		unsigned int arg[3])
{
	int		result;
	int		shift;
	int		i;

	i = -1;
	shift = 6;
	result = 0;
	while (++i < 3)
	{
		if (((codage >> shift) & 3) == IND_CODE)
			arg[i] = find_num(core->map, ((*fork)->curr_point + 2 + result), 2);
		else if (((codage >> shift) & 3) == DIR_CODE)
			arg[i] = find_num(core->map, ((*fork)->curr_point + 2 + result), 2);
		else if (((codage >> shift) & 3) == REG_CODE)
			arg[i] = find_num(core->map, ((*fork)->curr_point + 2 + result), 1);
		if (((codage >> shift) & 3) == IND_CODE)
			result += 2;
		else if (((codage >> shift) & 3) == DIR_CODE)
			result += 2;
		else if (((codage >> shift) & 3) == REG_CODE)
			result += 1;
		shift -= 2;
	}
	return (result);
}

void		load_index(t_core *core, t_fork **fork)
{
	unsigned int	codage;
	unsigned int	shift;
	unsigned int	arg[3];

	codage = find_num(core->map, ((*fork)->curr_point + 1), 1);
	shift = 1;
	if (!check_codage(codage, 10))
	{
		shift += 1 + select_params_li(core, fork, codage, arg);
		if (check_regs(core, fork, codage, arg))
			shift = 1;
		else
			(*fork)->registr[arg[2]] = find_num(core->map, (*fork)->curr_point
					+ (int)(arg[0] + arg[1]) % IDX_MOD, 4);
	}
	make_shift(fork, shift, arg[2]);
}
