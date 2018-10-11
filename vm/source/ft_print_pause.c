/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pause.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 11:25:06 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 12:57:40 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static void	clear_settings(t_core *core)
{
	core->nxt = 0;
	core->proc = 0;
	core->play = 0;
	core->pause = 1;
}

int			ft_print_pause(t_core *core, int i, int j, int tmp)
{
	int col;

	mlx_clear_window(MLX);
	mlx_put_image_to_window(MLX, core->img_ptr_frame, 0, 0);
	print_players(core);
	if (tmp)
		ft_print_winner(core);
	ft_print_info(core, 2);
	while (++i < MEM_SIZE / 64 + 1 + ((MEM_SIZE % 64) ? 1 : 0))
	{
		j = -1;
		while (++j < 64 && (i - 1) * 64 + j < MEM_SIZE)
		{
			core->tab[0] = _HEXL[(int)core->map[(i - 1) * 64 + j] / 16];
			core->tab[1] = _HEXL[(int)core->map[(i - 1) * 64 + j] % 16];
			core->tab[2] = ' ';
			core->tab[3] = '\0';
			mlx_string_put(MLX, (j + 1) * 25, i * 18,
					(col = ft_check_curr(core, (i - 1) * 64 + j, 0)) ?
					col : core->map_col[(i - 1) * 64 + j], core->tab);
		}
	}
	clear_settings(core);
	return (0);
}
