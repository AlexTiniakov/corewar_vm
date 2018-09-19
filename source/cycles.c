/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 19:24:24 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/19 13:57:03 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		cycles(unsigned char map[MEM_SIZE], t_fork *forks,
		t_header players[MAX_PLAYERS])
{
	t_fork *temp;

	if (map[0] == 0)
		map[0] += 0;
	temp = forks;
	while (temp)
	{
		ft_printf("%d %s\n%d %d %s\n", temp->parent_id,
				players[find_player(players, temp->parent_id)].prog_name,
				temp->curr_point, temp->opcode + 1,
				g_op_tab[find_operation(temp->opcode)].desc);
		
		temp = temp->next;
	}
}
