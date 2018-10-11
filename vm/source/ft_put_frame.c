/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:02:47 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/26 11:37:47 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static void	ft_draw_vert_lines(t_core *core, int col, int params[3])
{
	int i;
	int j;

	i = -1;
	while (++i < 10)
	{
		j = 9;
		while (++j < H - 10)
		{
			core->frame[(i * 4 + params[1] * j)] = col % 256;
			core->frame[(i * 4 + params[1] * j) + 1] = col / 256 % 256;
			core->frame[(i * 4 + params[1] * j) + 2] = col / 256 / 256 % 256;
			core->frame[((i + 1633) * 4 + params[1] * j)] = col % 256;
			core->frame[((i + 1633) * 4 + params[1] * j) + 1] = col / 256 % 256;
			core->frame[((i + 1633) * 4 + params[1] * j) + 2] = col / 256 /
				256 % 256;
			core->frame[((i + W - 10) * 4 + params[1] * j)] = col % 256;
			core->frame[((i + W - 10) * 4 + params[1] * j) + 1] = col /
				256 % 256;
			core->frame[((i + W - 10) * 4 + params[1] * j) + 2] = col / 256 /
				256 % 256;
		}
	}
}

static void	ft_draw_hor_lines(t_core *core, int col, int pars[3])
{
	int i;
	int j;

	i = -1;
	while (++i < W)
	{
		j = -1;
		while (++j < 10)
		{
			core->frame[(i * 4 + pars[1] * j)] = col % 256;
			core->frame[(i * 4 + pars[1] * j) + 1] = col / 256 % 256;
			core->frame[(i * 4 + pars[1] * j) + 2] = col / 256 / 256 % 256;
		}
	}
}

int			ft_put_frame(t_core *core)
{
	int	pars[3];

	core->img_ptr_frame = mlx_new_image(core->mlx_ptr, W, H);
	core->frame = mlx_get_data_addr(core->img_ptr_frame,
			&pars[0], &pars[1], &pars[2]);
	ft_draw_hor_lines(core, core->frame_color, pars);
	ft_draw_vert_lines(core, core->frame_color, pars);
	ft_memcpy(&core->frame[W * H * 4 - 40 * W], core->frame, 40 * W);
	mlx_put_image_to_window(core->mlx_ptr, core->win_ptr,
			core->img_ptr_frame, 0, 0);
	print_players(core);
	return (0);
}
