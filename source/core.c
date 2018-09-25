/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:40:54 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/23 14:25:34 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

t_core		*init_core(t_core *core, int ac, char **av)
{
	core->space = 1;
	core->visual = 0;
	core->nxt = 0;
	core->leaks = 0;
	core->dump = 0;
	core->mlx_ptr = NULL;
	core->win_ptr = NULL;
	init_map(core->map);
	init_players(core->players);
	core->forks = NULL;
	core->ac = ac;
	core->av = av;
	core->index = 0;
	core->pl_num = 0;
	core->count_live = 0;
	core->frame_color_num = 0;
	core->cycles_num = 0;
	core->play = 0;
	return (core);
}
