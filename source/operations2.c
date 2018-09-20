/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alive.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/20 15:09:19 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	store_index(unsigned char map[MEM_SIZE], t_fork **fork,
		t_header players[MAX_PLAYERS])
{
	ft_printf("store index!\n");
	map[0]+=0;
	players[0].start+=0;
	(*fork)->alive = 1;
}

void	forking(unsigned char map[MEM_SIZE], t_fork **fork,
		t_header players[MAX_PLAYERS])
{
	ft_printf("fork!\n");
	map[0]+=0;
	players[0].start+=0;
	(*fork)->alive = 1;
}

void	long_load(unsigned char map[MEM_SIZE], t_fork **fork,
		t_header players[MAX_PLAYERS])
{
	ft_printf("long load!\n");
	map[0]+=0;
	players[0].start+=0;
	(*fork)->alive = 1;
}

void	long_load_index(unsigned char map[MEM_SIZE], t_fork **fork,
		t_header players[MAX_PLAYERS])
{
	ft_printf("long load index!\n");
	map[0]+=0;
	players[0].start+=0;
	(*fork)->alive = 1;
}

void	long_forking(unsigned char map[MEM_SIZE], t_fork **fork,
		t_header players[MAX_PLAYERS])
{
	ft_printf("long fork!\n");
	map[0]+=0;
	players[0].start+=0;
	(*fork)->alive = 1;
}
