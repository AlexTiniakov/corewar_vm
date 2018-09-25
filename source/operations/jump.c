/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/24 21:55:00 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
** OKOKOKOKOKOKOKOK
** if fork's carry == 1 jump forward on DIR % IND_MOD index
** tested ok
*/

void	jump(t_core *core, t_fork **fork)
{
	unsigned int	dir;

	dir = find_num(core->map, (*fork)->curr_point + 1, 2);
	if ((*fork)->carry)
		(*fork)->curr_point += (int)dir % IDX_MOD;
	else
		(*fork)->curr_point += 3;
	(*fork)->curr_point %= MEM_SIZE;
	(*fork)->opcode = core->map[(*fork)->curr_point];
}
