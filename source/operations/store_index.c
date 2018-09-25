/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/24 22:36:14 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
**  OKOKOKOKOKOKOKOKOK
** take value from the register with first index and copies it into a map on
** position curr_position + second index + third index
*/

static int	select_params_store(t_core *core, t_fork **fork,
		unsigned int codage, unsigned int arg[3])
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
			arg[i] = find_num(core->map, (*fork)->curr_point + 2 + result, 2);
		else if (((codage >> shift) & 3) == DIR_CODE)
			arg[i] = find_num(core->map, (*fork)->curr_point + 2 + result, 2);
		else if (((codage >> shift) & 3) == REG_CODE)
			arg[i] = find_num(core->map, (*fork)->curr_point + 2 + result, 1);
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

static int	check_regs_store(t_core *core, t_fork **fork,
		unsigned int codage, unsigned int arg[3])
{
	int		i;
	int		shift;

	i = -1;
	shift = 6;
	while (++i < 3)
	{
		if (((codage >> shift) & 3) == IND_CODE)
			arg[i] = find_num(core->map, (*fork)->curr_point +
					(arg[i] % IDX_MOD), 4);
		else if (((codage >> shift) & 3) == REG_CODE &&
				(arg[i] == 0 || arg[i] > 16))
			return (1);
		else if (((codage >> shift) & 3) == REG_CODE &&
				(arg[i] != 0 && arg[i] < 17))
			arg[i] = (*fork)->registr[arg[i]];
		shift -= 2;
	}
	return (0);
}

void		store_index(t_core *core, t_fork **fork)
{
	unsigned int	codage;
	unsigned int	arg[3];
	unsigned int	shift;

	codage = find_num(core->map, (*fork)->curr_point + 1, 1);
	shift = 1;
	if (!check_codage(codage, 11))
	{
		shift += 1 + select_params_store(core, fork, codage, arg);
		if (check_regs_store(core, fork, codage, arg))
			shift = 1;
		else
			print_reg1(core, (*fork)->curr_point +
					(int)((arg[1] + arg[2])) % IDX_MOD, arg[0],
					find_player(core->players, (*fork)->parent_id) + 1);
	}
	make_shift(fork, shift, 0);
}
