/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spin_visual.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:30:51 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 20:15:02 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	iter_visual(t_core *core)
{
	int i;
	int j;
	int col;

	mlx_clear_window(core->mlx_ptr, core->win_ptr);
	mlx_put_image_to_window(core->mlx_ptr, core->win_ptr,
			core->img_ptr_frame, 0, 0);
	print_players(core);
	ft_print_info(core, 1);
	i = 0;
	while (++i < MEM_SIZE / 64 + 1 + ((MEM_SIZE % 64) ? 1 : 0))
	{
		j = -1;
		while (++j < 64 && (i - 1) * 64 + j < MEM_SIZE)
		{
			core->tab[0] = _HEXL[(int)core->map[(i - 1) * 64 + j] / 16];
			core->tab[1] = _HEXL[(int)core->map[(i - 1) * 64 + j] % 16];
			core->tab[2] = ' ';
			core->tab[3] = '\0';
			mlx_string_put(core->mlx_ptr, core->win_ptr,
					(j + 1) * 25, i * 18, (col = ft_check_curr(core,
							(i - 1) * 64 + j, 0)) ? col :
					core->map_col[(i - 1) * 64 + j], core->tab);
		}
	}
}

int		spin_visual(t_core *core)
{
	if (core->space && !(core->space && core->nxt))
	{
		return ((core->play || !core->nxt) && ((!core->pause) ?
					ft_print_pause(core, 0, -1, 0) : 0));
	}
	if (core->dump && core->cycles_num == core->dump)
		exit((ft_printf("game dumped on %d cycles\n", core->cycles_num) +
						print_map(core->map)) + _L);
	if (CYCLE_TO_DIE - core->cycles_to_die <= 0 || !cycle(core))
		return (core->play || !core->nxt ? ft_print_pause(core, 0, -1, 1) : 0);
	core->cycles_num++;
	if (core->cycles_num && !(core->cycles_num %
				(CYCLE_TO_DIE - core->cycles_to_die)))
		checkout(core);
	if (core->proc || core->step)
	{
		iter_visual(core);
		core->nxt = 0;
		core->proc = 0;
	}
	return (0);
}
