/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:00:43 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/13 19:46:22 by dskrypny         ###   ########.fr       */
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
