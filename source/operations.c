/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:09:43 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/19 12:22:36 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

short			find_operation(char opcode)
{
	short		i;

	i = -1;
	while (++i < 16)
		if (g_op_tab[i].opcode == opcode)
			return (opcode);
	return (0);
}

int				find_player(t_header players[MAX_PLAYERS], unsigned int id)
{
	int i;

	i = -1;
	while (players[++i].magic)
	   if (players[i].id == id)
		   return (i);
	return (-1);
}
