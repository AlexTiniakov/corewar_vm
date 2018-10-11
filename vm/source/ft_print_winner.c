/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_winner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 21:37:41 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 19:38:10 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static int	select_winner(t_core *core)
{
	int		i;
	int		index;
	int		last;

	i = -1;
	index = 0;
	last = 0;
	while (++i < MAX_PLAYERS && core->players[i].magic)
		if (core->players[i].last_live > last)
		{
			last = core->players[i].last_live;
			index = i;
		}
	return (index);
}

void		ft_print_winner(t_core *core)
{
	int		index;
	char	*s;

	index = select_winner(core);
	if (core->visual)
	{
		s = ft_itoa((int)core->players[index].id);
		mlx_string_put(MLX, CENTER, 800, 0xFF0000, "WINNER:");
		mlx_string_put(MLX, CENTER + 35 - 10 * ft_strlen(s) / 2,
				820, 0xFF0000, s);
		mlx_string_put(MLX, CENTER + 35 - 10 *
				ft_strlen(core->players[index].prog_name) / 2, 840, 0xFF0000,
				core->players[index].prog_name);
		free(s);
	}
	else
		ft_printf("Player %d (%s) won\n", core->players[index].id,
				core->players[index].prog_name);
}
