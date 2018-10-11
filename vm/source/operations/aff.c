/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alive.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 21:09:39 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
** OKOKOKOKOKOKOKOKOK
** gets a register index and prints a char from that register
** tested, ok
*/

static void	extended_aff(t_fork *fork, int reg)
{
	ft_printf("%-4d||%5{grn}s||r%d\n", fork->curr_point, "aff", reg);
}

void		aff(t_core *core, t_fork **fork)
{
	unsigned int	codage;
	int				reg;
	unsigned int	shift;

	shift = 1;
	codage = find_num(core->map, (*fork)->curr_point + 1, 1);
	if (!check_codage(codage, 16))
	{
		reg = find_num(core->map, (*fork)->curr_point + 2, 1);
		if (reg > 0 && reg < 17)
		{
			if (core->extended)
				ft_putchar((*fork)->registr[reg] % 256);
			shift = 3;
		}
	}
	if (core->extended)
		extended_aff(*fork, reg);
	(*fork)->curr_point = ((*fork)->curr_point + shift + MEM_SIZE) % MEM_SIZE;
	(*fork)->opcode = core->map[(*fork)->curr_point];
}
