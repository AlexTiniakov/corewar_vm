/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 19:24:24 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 20:11:39 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

/*
**	if ((pl_index = find_player(core->players, temp->parent_id)) == -1)
**	{
**		temp->curr_point += 1;
**		temp->opcode = core->map[temp->curr_point];
**		continue;
**	}
*/

static void		make_operation(t_core *core, t_fork *temp)
{
	temp->opcode = core->map[(temp->curr_point + MEM_SIZE) % MEM_SIZE];
	if (temp->opcode > 0 && temp->opcode < 17)
		temp->cycles_to_wait = ((temp->cycles_to_wait) ?
			temp->cycles_to_wait - 1 : g_op_tab[temp->opcode].cycles - 1);
	else
	{
		temp->curr_point = (temp->curr_point + 1 + MEM_SIZE) % MEM_SIZE;
		temp->opcode = core->map[temp->curr_point];
		return ;
	}
	if (!(temp->cycles_to_wait))
	{
		g_op_tab[temp->opcode].operation(core, &temp);
		core->proc = 1;
	}
}

int				cycle(t_core *core)
{
	t_fork			*temp;
	t_fork			*temp1;

	while (core->forks && !(core->forks->alive))
	{
		temp = core->forks->next;
		ft_memdel((void **)&(core->forks));
		core->forks = temp;
	}
	if (!core->forks)
		return (0);
	temp = core->forks;
	while (temp)
	{
		if ((temp1 = temp->next) && !temp->next->alive)
		{
			temp->next = temp1->next;
			ft_memdel((void **)&temp1);
			continue;
		}
		make_operation(core, temp);
		temp = temp->next;
	}
	return (1);
}
