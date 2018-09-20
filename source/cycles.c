/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 19:24:24 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/20 16:25:55 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		cycle(unsigned char map[MEM_SIZE], t_fork *forks,
		t_header players[MAX_PLAYERS])
{
	t_fork			*temp;
	int				oper_index;
	int				pl_index;

	temp = forks;
	while (temp)
	{
		if ((pl_index = find_player(players, temp->parent_id)) == -1)
			exit(1);
		if ((oper_index = find_operation(temp->opcode)) > -1)
			temp->cycles_to_wait = (temp->cycles_to_wait) ?
				temp->cycles_to_wait - 1 : g_op_tab[oper_index].cycles;
		else
			ft_printf("%{red}s\n", "Wrong opcode!!!");
		if (!(temp->cycles_to_wait))
			g_op_tab[oper_index].operation(map, &temp, players);
	//	ft_printf("%d %d %s %d\n", temp->curr_point, temp->opcode,
	//			g_op_tab[find_operation(temp->opcode)].desc, temp->cycles_to_wait);
		temp = temp->next;
	}
//	ft_printf("___________\n");
	//output
}
