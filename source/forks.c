/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:46:26 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/13 20:03:57 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void			init_fork(t_fork *fork, unsigned int id, unsigned int start)
{
	int i;

	fork->alive = 0;
	fork->carry = 0;
	fork->optcode = 0;
	fork->parent_id = id;
	fork->curr_point = start;
	fork->cycles_to_wait = 0;
	i = -1;
	while (++i < 16)
		fork->registr[i] = 0;
}
