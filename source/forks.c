/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:46:26 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/19 13:19:06 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void			init_fork(t_fork **fork, unsigned int id, unsigned int start,
		unsigned char optcode)
{
	int		i;
	t_fork	*temp;

	temp = (t_fork *)malloc(sizeof(t_fork));
	temp->alive = 1;
	temp->carry = 0;
	temp->parent_id = id;
	temp->curr_point = start;
	temp->cycles_to_wait = 0;
	i = -1;
	while (++i < REG_NUMBER)
		temp->registr[i] = 0;
	temp->opcode = optcode;
	temp->next = *fork;
	*fork = temp;
}
