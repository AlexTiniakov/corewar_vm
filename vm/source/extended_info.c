/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 11:19:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/27 11:33:35 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	extended_info(t_core *core, t_fork *fork, int opcode)
{
	int		i;

	if (!core->extended)
		return ;
	i = 0;
	while (i < 17 && g_op_tab[i].opcode != opcode)
		i++;
	ft_printf("%s at %d\n", g_op_tab[i].instruct, fork->curr_point);
}
