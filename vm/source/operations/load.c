/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 19:30:49 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
** OKOKOKOKOKOKOKOK
** loads to the register an int from direct cell or move kareta to index
** % IDX_MOD and loads int from there
** tested, all ok
*/

int			load_ind(t_core *core, t_fork **fork)
{
	unsigned int	arg[2];

	arg[0] = (int)find_num(core->map, ((*fork)->curr_point + 2), 2) % IDX_MOD;
	arg[1] = find_num(core->map, ((*fork)->curr_point + 4), 1);
	(core->extended) ? ft_printf("%d r%d\n", arg[0], arg[1]) : 0;
	if (arg[1] <= 0 && arg[1] > 16)
		return (1);
	core->map[((*fork)->curr_point + 2) % MEM_SIZE] = arg[0] / 256;
	core->map[((*fork)->curr_point + 3) % MEM_SIZE] = arg[0] % 256;
	core->map_col[((*fork)->curr_point + 2) % MEM_SIZE] =
		ft_check_curr(core, (*fork)->parent_id, 1);
	core->map_col[((*fork)->curr_point + 3) % MEM_SIZE] =
		ft_check_curr(core, (*fork)->parent_id, 1);
	arg[0] = find_num(core->map, (*fork)->curr_point + arg[0], 4);
	(*fork)->registr[arg[1]] = arg[0];
	return (5);
}

static void	norm(t_core *core, t_fork **fork, unsigned int *shift,
	unsigned int arg[2])
{
	(*shift) += 2;
	arg[0] = find_num(core->map, ((*fork)->curr_point + 2), 4);
	arg[1] = find_num(core->map, ((*fork)->curr_point + 6), 1);
}

void		load(t_core *core, t_fork **fork)
{
	unsigned int	codage;
	unsigned int	arg[2];
	unsigned int	shift;

	codage = find_num(core->map, ((*fork)->curr_point + 1), 1);
	(CD) ? ft_printf("%-4d||%5{grn}s||", (*fork)->curr_point, "ld") : 0;
	shift = 1;
	if (!check_codage(codage, 2))
	{
		shift = 5;
		if ((codage >> 6) == DIR_CODE)
		{
			norm(core, fork, &shift, arg);
			(core->extended) ? ft_printf("r%d r%d\n", arg[0], arg[1]) : 0;
			if (arg[1] > 0 && arg[1] < 17)
				(*fork)->registr[arg[1]] = arg[0];
			else
				shift = 1;
		}
		else
			shift = load_ind(core, fork);
	}
	else
		(CD) ? ft_putchar('\n') : NULL;
	make_shift(fork, shift, arg[1]);
}
