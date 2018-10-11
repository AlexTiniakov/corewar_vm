/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 21:05:05 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
**  OKOKOKOKOKOKOK
** take value from the register with first index and copies it in register,
** if second index is REG, or in map, if second index is IND
*/

static int	check_stores(t_core *core, t_fork **fork, unsigned int codage,
		unsigned int arg[2])
{
	arg[0] = find_num(core->map, (*fork)->curr_point + 2, 1);
	arg[1] = (codage == REG_CODE) ?
		find_num(core->map, (*fork)->curr_point + 3, 1) :
		find_num(core->map, (*fork)->curr_point + 3, 2);
	if ((codage == REG_CODE && (arg[1] == 0 || arg[1] > 16)) ||
			(arg[0] == 0 || arg[0] > 16))
		return (1);
	if (CD)
		ft_printf("r%d %s%d\n", arg[0], (codage == REG_CODE) ? "r" : "",
			arg[1]);
	arg[0] = (*fork)->registr[arg[0]];
	return (0);
}

void		store(t_core *core, t_fork **fork)
{
	unsigned int	codage;
	unsigned int	arg[2];
	unsigned int	shift;

	codage = find_num(core->map, (*fork)->curr_point + 1, 1);
	if (core->extended)
		ft_printf("%-4d||%5{grn}s||", (*fork)->curr_point, "st");
	shift = 1;
	if (!check_codage(codage, 3))
	{
		shift = 4 + ((((codage >> 4) & 3) == REG_CODE) ? 0 : 1);
		if (check_stores(core, fork, (codage >> 4) & 3, arg))
			shift = 1;
		else
		{
			if (((codage >> 4) & 3) == REG_CODE)
				(*fork)->registr[arg[1]] = arg[0];
			else
				print_reg1(core, (*fork)->curr_point + (int)arg[1] % IDX_MOD,
						arg[0], find_player(core->players,
							(*fork)->parent_id) + 1);
		}
	}
	make_shift(fork, shift, 0);
}
