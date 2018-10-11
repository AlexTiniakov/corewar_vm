/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 22:11:37 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/28 20:14:14 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static int	ft_exit(int key, void *param)
{
	t_core *core;

	core = (t_core *)param;
	key = 0;
	exit(0);
	return (0);
}

static int	key_hook(int key, void *param)
{
	t_core *core;

	core = (t_core *)param;
	if (key == 53)
		exit(_L);
	else if (key == 49)
	{
		core->space = core->space ? 0 : 1;
		core->play = 1;
		core->pause = 0;
	}
	else if (key == 124 && core->space)
		core->nxt = 1;
	return (0);
}

static int	init_visual(t_core *core)
{
	int i;
	int j;
	int col;

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
			mlx_string_put(core->mlx_ptr, core->win_ptr, (j + 1) * 25, i * 18,
					(col = ft_check_curr(core, (i - 1) * 64 + j, 0)) ? col :
					core->map_col[(i - 1) * 64 + j], core->tab);
		}
	}
	return (0);
}

void		ft_visual(t_core *core)
{
	core->mlx_ptr = mlx_init();
	core->win_ptr = mlx_new_window(core->mlx_ptr, W, H, "corewar");
	ft_print_info(core, 0);
	init_visual(core);
	mlx_hook(core->win_ptr, 2, 5, key_hook, (void *)core);
	mlx_hook(core->win_ptr, 17, 5, ft_exit, (void *)core);
	mlx_loop_hook(core->mlx_ptr, spin_visual, (void *)core);
	mlx_loop(core->mlx_ptr);
}
