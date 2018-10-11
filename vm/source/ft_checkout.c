/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 10:48:45 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 20:24:05 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static void	clear_players(t_core *core)
{
	int		pl_index;

	pl_index = -1;
	while (core->players[++pl_index].magic && pl_index < MAX_PLAYERS)
	{
		if (!core->players[pl_index].live_num)
		{
			core->players_live -= core->players[pl_index].alive ? 1 : 0;
			core->players[pl_index].alive = 0;
		}
		core->players[pl_index].live_num = 0;
	}
}

void		checkout(t_core *core)
{
	t_fork	*temp;

	core->checkups += 1;
	clear_players(core);
	temp = core->forks;
	while (temp)
	{
		if (!temp->live_num && temp->alive)
		{
			temp->alive = 0;
			core->players[find_player(core->players,
					temp->parent_id)].nb_proc--;
		}
		temp->live_num = 0;
		temp = temp->next;
	}
	if (core->checkups >= MAX_CHECKS || core->players_live > 21)
	{
		core->cycles_to_die += (CYCLE_DELTA);
		core->checkups = 0;
	}
}
