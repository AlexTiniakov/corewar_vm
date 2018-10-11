/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_players.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:32:28 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 13:10:09 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void			print_live_proc(t_core *core, int i, int c)
{
	char		*s;

	s = ft_itoa((int)core->players[i].nb_proc);
	mlx_string_put(MLX, INFO + TAB, Y + DY + i * 100, c, "Proceses");
	mlx_string_put(MLX, INFO + LP2, Y + DY + i * 100, c, s);
	free(s);
	s = ft_itoa((int)core->players[i].last_live);
	mlx_string_put(MLX, INFO + TAB, Y + 2 * DY + i * 100, c, "Last live");
	mlx_string_put(MLX, INFO + LP2 + 10, Y + 2 * DY + i * 100, c, s);
	free(s);
}

void			print_players(t_core *core)
{
	static int	colors[] = {0xff0000, 0x00ff00, 0x0000ff, 0xffff00, 0xff00ff,
		0x00ffff};
	int			i;
	char		*s;
	int			c;

	i = -1;
	mlx_string_put(MLX, INFO, Y - DY, 0x9116AD, "Champions:");
	while (++i < MAX_PLAYERS && core->players[i].magic)
	{
		c = (int)core->players[i].nb_proc > 0 ? 0xFFFFFF : 0x8E8177;
		mlx_string_put(MLX, INFO, Y + i * 100, c, "Player");
		s = ft_itoa((int)core->players[i].id);
		mlx_string_put(MLX, INFO + LP, Y + i * 100, c, s);
		mlx_string_put(MLX, INFO + LP1 + (core->players[i].strlen - 2) * 10,
						Y + i * 100, c, ":");
		free(s);
		mlx_string_put(MLX, INFO + LP2 + (core->players[i].strlen - 2) * 10,
		Y + i * 100, (int)core->players[i].nb_proc > 0 ? colors[i] : 0x8E8177,
				core->players[i].prog_name);
		print_live_proc(core, i, c);
	}
}
