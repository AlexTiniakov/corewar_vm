/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:15:13 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/24 21:49:58 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int				check_flags(t_core *core)
{
	if (!ft_strcmp(core->av[core->index], "-dump"))
	{
		if (core->index < core->ac - 1 && ft_str_isdigit(core->av[core->index])
				&& (core->dump = ft_atoi(core->av[core->index + 1])) > 0)
			return (2);
		else
			exit(usage());
	}
	if (!ft_strcmp(core->av[core->index], "-l"))
		return (ABS(core->leaks = 1));
	if (!ft_strcmp(core->av[core->index], "-n"))
	{
		if (core->index < core->ac - 1 && (core->dump =
					ft_atoi(core->av[core->index + 1])) > 0)
			return (2);
		else
			exit(usage());
	}
	if (!ft_strcmp(core->av[core->index], "-v"))
		return (ABS(core->visual = 1));
	return (0);
}

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

static int		reader(t_core *core)
{
	int				fd;

	while (++core->index < core->ac)
	{
		if ((core->index += check_flags(core)) >= core->ac)
            break ;
		if ((fd = open(core->av[core->index], O_RDWR)) < 0)
			error("error: Invalid file");
		if (read_player(fd, &(core->players[core->pl_num]), core->pl_num))
			error("error: Invalid player");
		else
			core->pl_num++;
		close(fd);
	}
	if (!(core->pl_num))
		error("error: No players");
	if (core->pl_num > MAX_PLAYERS)
		error("error: Too many players");
	count_start(core);
	return (0);
}

static void		put_players(t_core *core)
{
	int	i;
	unsigned int	j;

	i = -1;
	while (++i < core->pl_num)
	{
		j = -1;
		while (++j < core->players[i].prog_size)
		{
			core->map[j + core->players[i].start] = core->players[i].program[j];
			core->map_col[j + core->players[i].start] = ft_check_curr(core, core->players[i].id, 1);
		}
	}
}

//delete this func
void			print_forks(t_fork *forks)
{
	t_fork *temp;
	int i;

	temp = forks;
	while (temp)
	{
		ft_printf("id %x %d carry %d|", temp->parent_id, temp->alive, temp->carry);
		i = 0;
		while (++i <= REG_NUMBER)
			ft_printf("%08x|", temp->registr[i]);
		ft_printf("%d %d %d|\n", temp->curr_point, temp->opcode,
				temp->cycles_to_wait);
		temp = temp->next;
	}
	ft_printf("///////////////\n");
}



int				main(int ac, char *av[])
{
	t_core			core;	
	int				i;

	if (ac == 1)
		exit(usage());
	reader(init_core(&core, ac, av));
	///
	ft_put_white(&core);
	///
	put_players(&core);
	//print_map(core.map);
	i = -1;
	while (++i < core.pl_num)
		init_fork(&(core.forks), core.players[i].id,
				core.players[i].start, core.map[core.players[i].start]);
	print_forks(core.forks);
	i = 0;
	///
	core.visual ? ft_visual(&core) : ft_cycle(&core);
	///
	/*while (++i <= 27)
		cycle(&core);*/
	print_forks(core.forks);
	//print_map(core.map);
//	LEAK

	print_forks(core.forks);
	return (0);
}
