/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alive.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/20 15:09:50 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	anding(unsigned char map[MEM_SIZE], t_fork **fork,
		t_header players[MAX_PLAYERS])
{
	ft_printf("and!\n");
	map[0]+=0;
	players[0].start+=0;
	(*fork)->alive = 1;
}

void	oring(unsigned char map[MEM_SIZE], t_fork **fork,
		t_header players[MAX_PLAYERS])
{
	ft_printf("or!\n");
	map[0]+=0;
	players[0].start+=0;
	(*fork)->alive = 1;
}

void	xoring(unsigned char map[MEM_SIZE], t_fork **fork,
		t_header players[MAX_PLAYERS])
{
	ft_printf("xor!\n");
	map[0]+=0;
	players[0].start+=0;
	(*fork)->alive = 1;
}

void	jump(unsigned char map[MEM_SIZE], t_fork **fork,
		t_header players[MAX_PLAYERS])
{
	ft_printf("jump!\n");
	map[0]+=0;
	players[0].start+=0;
	(*fork)->alive = 1;
}

void	load_index(unsigned char map[MEM_SIZE], t_fork **fork,
		t_header players[MAX_PLAYERS])
{
	ft_printf("load index!\n");
	map[0]+=0;
	players[0].start+=0;
	(*fork)->alive = 1;
}
