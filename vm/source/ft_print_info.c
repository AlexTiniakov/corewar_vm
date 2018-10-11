/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:31:43 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/28 12:55:47 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static void	ft_print_info3(t_core *core)
{
	char		*s;

	s = ft_itoa(MAX_CHECKS);
	mlx_string_put(MLX, INFO, Y + (core->pl_num + 1) * 100 + 20 + 60, 0x9116AD,
			"MAX_CHECKS:");
	mlx_string_put(MLX, INFO + LP2 * 2, Y + (core->pl_num + 1) * 100 + 20 + 60,
			0xFFFFFF, s);
	free(s);
	mlx_string_put(MLX, INFO, Y + (core->pl_num) * 100, 0x9116AD,
			"Live breakdown for current period:");
	mlx_string_put(MLX, INFO, Y + (core->pl_num) * 100 + 50, 0x9116AD,
			"Live breakdown for the whole game:");
}

static void	ft_print_info2(t_core *core)
{
	char		*s;

	s = ft_itoa(CYCLE_TO_DIE - core->cycles_to_die);
	mlx_string_put(MLX, INFO, Y + (core->pl_num + 1) * 100 + 20, 0x9116AD,
			"CYCLE_TO_DIE:");
	mlx_string_put(MLX, INFO + LP2 * 2, Y + (core->pl_num + 1) * 100 + 20,
			0xFFFFFF, s > 0 ? s : "0");
	free(s);
	s = ft_itoa(CYCLE_DELTA - core->cycles_delta);
	mlx_string_put(MLX, INFO, Y + (core->pl_num + 1) * 100 + 20 + 20, 0x9116AD,
			"CYCLE_DELTA:");
	mlx_string_put(MLX, INFO + LP2 * 2, Y + (core->pl_num + 1) * 100 + 20 + 20,
			0xFFFFFF, s);
	free(s);
	s = ft_itoa(NBR_LIVE);
	mlx_string_put(MLX, INFO, Y + (core->pl_num + 1) * 100 + 20 + 40, 0x9116AD,
			"NBR_LIVE:");
	mlx_string_put(MLX, INFO + LP2 * 2, Y + (core->pl_num + 1) * 100 + 20 + 40,
			0xFFFFFF, s);
	free(s);
}

int			ft_print_info(t_core *core, int i)
{
	static int	colors[] = {0x150063, 0x9116AD, 0xFFFFFF};
	int			proc;
	char		*s;

	core->frame_color = colors[core->frame_color_num];
	if (!i)
		return (ft_put_frame(core));
	mlx_string_put(MLX, 1830, 20, (i == 1 && !core->nxt) ? 0x00BC2F : 0xB72700,
			(i == 1 && !core->nxt) ? "**  PLAY  **" : "** PAUSED **");
	s = ft_itoa(core->cycles_num);
	mlx_string_put(MLX, INFO, 50, 0x9116AD, "Cycle:");
	mlx_string_put(MLX, INFO + LP2, 50, 0xFFFFFF, s);
	free(s);
	i = -1;
	proc = 0;
	while (++i < MAX_PLAYERS && core->players[i].magic)
		proc += (int)core->players[i].nb_proc;
	s = ft_itoa(proc);
	mlx_string_put(MLX, INFO, 50 + DY, 0x9116AD, "Proceses:");
	mlx_string_put(MLX, INFO + LP2, 50 + DY, 0xFFFFFF, s);
	free(s);
	ft_print_info2(core);
	ft_print_info3(core);
	ft_print_lines(core);
	return (0);
}
