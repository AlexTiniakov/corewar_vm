/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/24 22:59:36 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
** checks player and says it's alive
** tested, ok
*/

void	alive(t_core *core, t_fork **fork)
{
	unsigned int	reg;
	int				pl_index;

	reg = find_num(core->map, (*fork)->curr_point + 1, 4);
	if ((pl_index = find_player(core->players, reg)) >= 0)
	{
		core->players[pl_index].alive = 1;
		(!core->visual) ? ft_printf("A process shows that player %d (%s)%s",
				pl_index, core->players[pl_index].prog_name, " is alive!\n") :
			0;
		(*fork)->alive = 1;
	}
	make_shift(fork, 5, 0);
}
