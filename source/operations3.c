/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alive.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/20 15:10:44 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	aff(unsigned char map[MEM_SIZE], t_fork **fork,
		t_header players[MAX_PLAYERS])
{
	ft_printf("aff!\n");
	map[0]+=0;
	players[0].start+=0;
	(*fork)->alive = 1;
}
