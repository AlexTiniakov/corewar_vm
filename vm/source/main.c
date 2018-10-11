/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:15:13 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 16:10:50 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static void		count_start(t_core *core)
{
	int				i;
	int				delta;
	int				point;

	i = -1;
	delta = MEM_SIZE / core->pl_num;
	point = 0;
	while (++i < core->pl_num)
	{
		core->players[i].start = point;
		point += delta;
	}
}

static void		put_players(t_core *core)
{
	int				i;
	unsigned int	j;

	i = -1;
	while (++i < core->pl_num)
	{
		j = -1;
		while (++j < core->players[i].prog_size)
		{
			core->map[j + core->players[i].start] = core->players[i].program[j];
			core->map_col[j + core->players[i].start] =
				ft_check_curr(core, core->players[i].id, 1);
		}
	}
}

int				main(int ac, char *av[])
{
	t_core			core;
	int				i;

	if (ac == 1)
		exit(usage());
	header_validation(&core);
	reader(init_core(&core, ac, av));
	count_start(&core);
	ft_put_white(&core);
	put_players(&core);
	i = -1;
	while (++i < core.pl_num)
		init_fork(&(core.forks), core.players[i].id,
				core.players[i].start, core.map[core.players[i].start]);
	core.visual ? ft_visual(&core) : ft_term(&core);
	return (core.leaks ? LEAK : 0);
}
