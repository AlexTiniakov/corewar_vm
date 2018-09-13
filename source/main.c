/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:15:13 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/13 20:03:59 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

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

	i = 0;
	while (i < pl_num)
	{
		j = 0;
		while (j < players[i].prog_size)
		{
			map[j + players[i].start] = players[i].program[j];
			j++;
		}
		i++;
	}
}

int				main(int ac, char *av[])
{
	unsigned char	map[MEM_SIZE];
	t_header		players[MAX_PLAYERS];
	t_fork			forks[MAX_PLAYERS];
	unsigned int	pl_num;
	unsigned int	i;

	if (ac == 1)
		return (1);
	pl_num = reader(ac, av, players);
	count_start(pl_num, players);
	init_map(map);
	i = -1;
	while (++i < pl_num)
		init_fork(&forks[i], players[i].id, players[i].start);
	put_players(pl_num, players, map);
	print_map(map);
	i = -1;
	while (++i < pl_num)
	{
		forks[i].optcode = map[forks[i].curr_point];
		ft_printf("fork %d, parent %d, sp = %d, code = %d\n", i, forks[i].parent_id,
				forks[i].curr_point, forks[i].optcode);
	}
//	system("leaks corewar");
	return (0);
}
