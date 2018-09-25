/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alive.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/24 20:25:51 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
** OKOKOKOKOKOKOKOKOK
** gets a register index and prints a char from that register
** tested, ok
*/

void	aff(t_core *core, t_fork **fork)
{
	unsigned int	codage;
	unsigned int	reg;
	unsigned int	shift;

	shift = 1;
	codage = find_num(core->map, (*fork)->curr_point + 1, 1);
	if (!check_codage(codage, 16))
	{
		reg = find_num(core->map, (*fork)->curr_point + 2, 1);
		if (reg > 0 && reg < 17)
		{
			ft_putchar((*fork)->registr[reg] % 256);
			shift = 3;
		}
	}
	(*fork)->curr_point = ((*fork)->curr_point + shift + MEM_SIZE) % MEM_SIZE;
	(*fork)->opcode = core->map[(*fork)->curr_point];
}
