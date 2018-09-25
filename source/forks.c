/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:46:26 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/24 22:48:38 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void			init_fork(t_fork **fork, unsigned int id, unsigned int start,
		unsigned char optcode)
{
	t_fork	*temp;
	int		i;

	temp = (t_fork *)malloc(sizeof(t_fork));
	temp->alive = 1;
	temp->carry = 0;
	temp->parent_id = id;
	temp->curr_point = (start + MEM_SIZE) % MEM_SIZE;
	temp->cycles_to_wait = 0;
	temp->opcode = optcode;
	temp->registr[0] = 1;
	temp->registr[1] = id;
	i = 1;
	while (++i <= REG_NUMBER)
		temp->registr[i] = 0;
	temp->next = *fork;
	*fork = temp;
}

void			copy_fork(t_fork *father, t_fork **fork, unsigned int sp)
{
	t_fork	*temp;
	int		i;

	temp = (t_fork *)malloc(sizeof(t_fork));
	temp->alive = father->alive;
	temp->carry = father->carry;
	temp->parent_id = father->parent_id;
	temp->curr_point = (father->curr_point + sp + MEM_SIZE) % MEM_SIZE;
	temp->cycles_to_wait = father->cycles_to_wait;
	temp->opcode = father->opcode;
	i = -1;
	while (++i <= REG_NUMBER)
		temp->registr[i] = father->registr[i];
	temp->registr[1] = father->parent_id;
	temp->next = *fork;
	*fork = temp;
}
