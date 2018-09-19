/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:15:13 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/19 13:22:21 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"
# include <stdio.h>

static int		reader(int ac, char *av[], t_header players[MAX_PLAYERS])
{
	int				i;
	int				fd;
	int				curr_pl;

	i = 0;
	curr_pl = 0;
	init_players(players);
	while (++i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) < 0)
			continue ;
		if (read_player(fd, &(players[curr_pl])))
			exit(1);
		else
		{
			players[curr_pl].id = curr_pl;
			curr_pl++;
		}
		close(fd);
	}
	return (curr_pl);
}

static void		count_start(int pl_num, t_header players[MAX_PLAYERS])
{
	int				i;
	int				delta;
	int				point;

	i = -1;
	delta = MEM_SIZE / pl_num;
	point = 0;
	while (++i < pl_num)
	{
		players[i].start = point;
		point += delta;
	}
}

static void		put_players(unsigned int pl_num, t_header players[MAX_PLAYERS],
		unsigned char map[MEM_SIZE])
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < pl_num)
	{
		j = -1;
		while (++j < players[i].prog_size)
			map[j + players[i].start] = players[i].program[j];
	}
}

int				main(int ac, char *av[])
{
	unsigned char	map[MEM_SIZE];
	t_header		players[MAX_PLAYERS];
	t_fork			*forks;
	unsigned int	pl_num;
	unsigned int	i;

	forks = NULL;
	if (ac == 1)
		return (1);
	pl_num = reader(ac, av, players);
	count_start(pl_num, players);
	init_map(map);
	put_players(pl_num, players, map);
	print_map(map);

	i = -1;
	while (++i < pl_num)
		init_fork(&forks, players[i].id, players[i].start, map[players[i].start]);

	cycles(map, forks, players);
//	system("leaks corewar");
	return (0);
}
