/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:39:43 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 11:19:48 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_put_white(t_core *core)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
		core->map_col[i] = 0x8E8177;
}

int		ft_check_curr(t_core *core, unsigned int pos, int i)
{
	static int	colors[] = {0xff14cf, 0x4CFF00, 0x14cfFF, 0xffff00, 0xff00ff,
		0x00ffff};
	static int	colors1[] = {0xaf0000, 0x00af00, 0x0000af, 0xafaf00, 0xaf00af,
		0x00afaf};
	t_fork		*temp;
	int			index;

	temp = core->forks;
	if (i == 0)
	{
		while (temp)
		{
			index = find_player(core->players, temp->parent_id);
			if (pos == temp->curr_point)
				return (abs(index) < 7 ?
						colors[abs(index)] : 0xff);
				temp = temp->next;
		}
	}
	else if (i == 1)
	{
		index = find_player(core->players, pos);
		return (abs(index) < 7 ? colors1[abs(index)] : 0xffffff);
	}
	return (0);
}

/*
** 	debug func
*/

void	print_forks(t_fork *forks)
{
	t_fork	*temp;
	int		i;

	temp = forks;
	while (temp)
	{
		ft_printf("id %5d %d carry %d|",
				temp->parent_id, temp->alive, temp->carry);
		i = 0;
		while (++i <= REG_NUMBER)
			ft_printf("%08x|", temp->registr[i]);
		ft_printf("%d %d %d|\n", temp->curr_point, temp->opcode,
				temp->cycles_to_wait);
		temp = temp->next;
	}
	ft_printf("///////////////\n");
}

int		check_ids(t_core *core, unsigned int id)
{
	int i;

	i = -1;
	while (++i < MAX_PLAYERS && core->players[i].magic)
	{
		if (core->players[i].id == id)
			return (1);
	}
	return (0);
}
