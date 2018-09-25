/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:00:43 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/24 22:48:03 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		init_map(unsigned char map[MEM_SIZE])
{
	int		i;

	i = -1;
	while (++i < MEM_SIZE)
		map[i] = 0;
}

void		print_map(unsigned char map[MEM_SIZE])
{
	int		i;
	short	j;
	char	*s;

	j = 0;
	i = -1;
	while (++i < MEM_SIZE)
	{
		s = ft_itoa_base(map[i], 16);
		ft_printf("%0*s%c", IND_SIZE, s, (i % 64 == 63) ? '\n' : ' ');
		free(s);
	}
}

void		print_reg1(t_core *core, unsigned int index,
		unsigned int argument, int id)
{
	static int		colors[] = {0x7f0000, 0x007f00, 0x00007f, 0x7f7f00,
		0x7f007f, 0x007f7f};
	int				x1;
	unsigned int	x2;

	x1 = argument / 65536;
	x2 = argument % 65536;
	core->map[(index + MEM_SIZE) % MEM_SIZE] = x1 / 256;
	core->map[(index + 1 + MEM_SIZE) % MEM_SIZE] = x1 % 256;
	core->map[(index + 2 + MEM_SIZE) % MEM_SIZE] = x2 / 256;
	core->map[(index + 3 + MEM_SIZE) % MEM_SIZE] = x2 % 256;
	x1 = -1;
	while (++x1 < 4)
		core->map_col[(index + x1 + MEM_SIZE) % MEM_SIZE] = id > 0 && id < 7
			? colors[id - 1] : 0xffffff;
}
