/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_term.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:52:25 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/28 20:29:15 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		ft_term(t_core *core)
{
	while (cycle(core))
	{
		core->cycles_num++;
		if (core->dump && core->cycles_num == core->dump)
			exit((ft_printf("game dumped on %d cycles\n", core->cycles_num) +
						print_map(core->map)) + _L);
		if (core->cycles_num && !(core->cycles_num %
					(CYCLE_TO_DIE - core->cycles_to_die)))
			checkout(core);
		if (CYCLE_TO_DIE - core->cycles_to_die <= 0)
			break ;
	}
	ft_print_winner(core);
	return (0);
}
