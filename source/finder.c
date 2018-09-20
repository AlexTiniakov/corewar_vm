/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:09:43 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/20 16:16:43 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

short			find_operation(char opcode)
{
	short		i;

	i = -1;
	while (++i < 16)
		if (g_op_tab[i].opcode == opcode)
			return (i);
	return (-1);
}

int				find_player(t_header players[MAX_PLAYERS], unsigned int id)
{
	int i;

	i = -1;
	while (players[++i].magic)
	{
		if (players[i].id == id)
			return (i);
	}
	return (-1);
}

unsigned int	find_num(unsigned char map[MEM_SIZE], unsigned int index,
		short size)
{
	int				ex;
	unsigned int	res;
	int				i;

	if (size == 1)
		return (map[index]);
	ex = 1;
	res = 0;
	i = size;
	while (--i >= 0)
	{
		res += ex * (map[index + i] % 16);
		ex *= 16;
		res += ex * (map[index + i] / 16);
		ex *= 16;
	}
	return (res);
}
