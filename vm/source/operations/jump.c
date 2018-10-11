/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 19:19:54 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
** OKOKOKOKOKOKOKOK
** if fork's carry == 1 jump forward on DIR % IND_MOD index
** tested ok
*/

static void	extended_jump(t_fork *fork, int arg)
{
	ft_printf("%-4d||%5{grn}s||%%%d", fork->curr_point, "zjmp", arg);
}

void		jump(t_core *core, t_fork **fork)
{
	unsigned int	dir;

	dir = find_num(core->map, (*fork)->curr_point + 1, 2);
	if (core->extended)
		extended_jump(*fork, (int)dir);
	(*fork)->curr_point += ((*fork)->carry) ? (int)dir % IDX_MOD : 3;
	(*fork)->curr_point %= MEM_SIZE;
	if (core->extended)
		((*fork)->carry) ? ft_printf("||success\n") : ft_printf("\n");
	(*fork)->opcode = core->map[(*fork)->curr_point];
}
