/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alive.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/20 16:26:06 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	alive(unsigned char *map, t_fork **fork,
		t_header players[MAX_PLAYERS])
{
	unsigned int	reg;
	int				pl_index;

	reg = find_num(map, (*fork)->curr_point + 1, 4);
	if ((pl_index = find_player(players, reg)) >= 0)
		players[pl_index].alive = 1;
	ft_printf("A process shows that player %d (%s) is alive\n", pl_index,
			players[pl_index].prog_name);
	(*fork)->alive = 1;
	(*fork)->curr_point += 5;
	(*fork)->opcode = map[(*fork)->curr_point];
}

void	load(unsigned char map[MEM_SIZE], t_fork **fork,
		t_header players[MAX_PLAYERS])
{
	unsigned int	codage;

	ft_printf("load!\n");
	codage = find_num(map, (*fork)->curr_point + 1, 1);
	ft_printf("%{red}s %d %s\n", "codage", codage, ft_itoa_base(codage, 2));
	map[0]+=0;
	players[0].start+=0;
}

void	store(unsigned char map[MEM_SIZE], t_fork **fork,
		t_header players[MAX_PLAYERS])
{
	ft_printf("store!\n");
	map[0]+=0;
	players[0].start+=0;
	(*fork)->alive = 1;
}

void	addition(unsigned char map[MEM_SIZE], t_fork **fork,
		t_header players[MAX_PLAYERS])
{
	ft_printf("addition!\n");
	map[0]+=0;
	players[0].start+=0;
	(*fork)->alive = 1;
}

void	substract(unsigned char map[MEM_SIZE], t_fork **fork,
		t_header players[MAX_PLAYERS])
{
	ft_printf("substraction!\n");
	map[0]+=0;
	players[0].start+=0;
	(*fork)->alive = 1;
}
