/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 17:40:08 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 12:46:05 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static void	count_total(t_core *core, int *cur, int *total)
{
	int i;
	int total_cur;
	int total_all;

	i = -1;
	total_cur = 0;
	total_all = 0;
	while (++i < MAX_PLAYERS && core->players[i].magic)
	{
		total_cur += core->players[i].live_num;
		total_all += core->players[i].hole_game_live_num;
	}
	*cur = total_cur;
	*total = total_all;
}

static void	print_total_cur(t_core *core, int total_cur, int colors[])
{
	int		i;
	int		j1;
	double	a;

	i = -1;
	j1 = 0;
	if (total_cur)
		while (++i < MAX_PLAYERS && core->players[i].magic && (a = 40.0 *
					(1.0 - (double)(total_cur - core->players[i].live_num) /
					total_cur)) < 41)
			while (a-- > 0 && ++j1 < 41)
				mlx_string_put(MLX, INFO + j1 * 10, Y + (core->pl_num) * 100 +
						25, colors[i], "-");
	else
		while (++j1 < 41)
			mlx_string_put(MLX, INFO + j1 * 10, Y + (core->pl_num) * 100 + 25,
					0x8E8177, "-");
}

static void	print_total_all(t_core *core, int total_all, int colors[])
{
	int		i;
	int		j2;
	double	b;

	i = -1;
	j2 = 0;
	if (total_all)
		while (++i < MAX_PLAYERS && core->players[i].magic && (b =
					40.0 * (1.0 - (double)(total_all -
					core->players[i].hole_game_live_num) / total_all)) < 41)
			while (b-- > 0 && ++j2 < 41)
				mlx_string_put(MLX, INFO + j2 * 10, Y +
						(core->pl_num) * 100 + 75, colors[i], "-");
	else
		while (++j2 < 41)
			mlx_string_put(MLX, INFO + j2 * 10, Y + (core->pl_num) * 100 + 75,
					0x8E8177, "-");
}

void		ft_print_lines(t_core *core)
{
	static int	colors[] = {0xff0000, 0x00ff00, 0x0000ff, 0xffff00, 0xff00ff,
		0x00ffff};
	int			total_cur;
	int			total_all;

	mlx_string_put(MLX, INFO, Y + (core->pl_num) * 100 + 25, 0x8E8177, "[");
	mlx_string_put(MLX, INFO, Y + (core->pl_num) * 100 + 75, 0x8E8177, "[");
	count_total(core, &total_cur, &total_all);
	print_total_cur(core, total_cur, colors);
	print_total_all(core, total_all, colors);
	mlx_string_put(MLX, INFO + 410, Y + (core->pl_num) * 100 + 25,
			0x8E8177, "]");
	mlx_string_put(MLX, INFO + 410, Y + (core->pl_num) * 100 + 75,
			0x8E8177, "]");
}
