/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:40:54 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 16:30:45 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static void	init_core2(t_core *core)
{
	core->space = 1;
	core->step = 0;
	core->visual = 0;
	core->nxt = 0;
	core->leaks = 0;
	core->dump = 0;
	core->pause = 0;
}

t_core		*init_core(t_core *core, int ac, char **av)
{
	core->mlx_ptr = NULL;
	core->win_ptr = NULL;
	init_map(core->map);
	init_players(core->players);
	core->forks = NULL;
	core->ac = ac;
	core->av = av;
	core->index = 1;
	core->pl_num = 0;
	core->players_live = 0;
	core->frame_color_num = 0;
	core->cycles_num = 0;
	core->cycles_to_die = 0;
	core->next_player_index = 0;
	core->cycles_delta = 0;
	core->play = 0;
	core->last_live = 0;
	core->checkups = 0;
	init_core2(core);
	return (core);
}
