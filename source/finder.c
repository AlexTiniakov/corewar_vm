/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:09:43 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/24 22:51:47 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

/*
**searching for operation
*/

short			find_operation(char opcode)
{
	short		i;

	i = -1;
	while (++i < 16)
		if (g_op_tab[i].opcode == opcode)
			return (i);
	return (-1);
}

/*
** searching for player
*/

int				find_player(t_header players[MAX_PLAYERS], unsigned int id)
{
	int i;

	i = -1;
	while (players[++i].magic && i < MAX_PLAYERS)
	{
		if (players[i].id == id)
			return (i);
	}
	return (-1);
}

/*
** reading {size} bytes from map, beginning at {index}
** and transform them into an integer
*/

unsigned int	find_num(unsigned char map[MEM_SIZE], unsigned int index,
		short size)
{
	int				ex;
	unsigned int	res;
	int				i;

	if (size == 1)
		return (map[(index + MEM_SIZE) % MEM_SIZE]);
	ex = 1;
	res = 0;
	i = size;
	while (--i >= 0)
	{
		res += ex * (map[(index + i + MEM_SIZE) % MEM_SIZE] % 16);
		ex *= 16;
		res += ex * (map[(index + i + MEM_SIZE) % MEM_SIZE] / 16);
		ex *= 16;
	}
	if (size == 1)
		res = (unsigned char)res;
	else if (size == 2)
		res = (short)res;
	else
		res = (unsigned int)res;
	return (res);
}
