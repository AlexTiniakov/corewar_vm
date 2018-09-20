/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:46:26 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/20 15:02:39 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void			init_fork(t_fork **fork, unsigned int id, unsigned int start,
		unsigned char optcode)
{
	t_fork	*temp;

	temp = (t_fork *)malloc(sizeof(t_fork));
	temp->alive = 0;
	temp->carry = 0;
	temp->parent_id = id;
	temp->curr_point = (start == 3072) ? 3087 : start;
	temp->cycles_to_wait = 0;
	temp->opcode = (start == 3072) ? 1 : optcode;
	temp->next = *fork;
	*fork = temp;
}
