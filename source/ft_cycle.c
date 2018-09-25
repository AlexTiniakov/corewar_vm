/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 22:11:37 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/23 22:11:38 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void ft_put_white(t_core *core)
{
	int i;
	i = -1;

	while (++i < MEM_SIZE)
		core->map_col[i] = 0x8E8177;
}

int ft_check_curr(t_core *core, unsigned int pos, int i)
{
    static int colors[] = {0xff0000, 0x00ff00, 0x0000ff, 0xffff00, 0xff00ff, 0x00ffff};
    static int colors1[] = {0x7f0000, 0x007f00, 0x00007f, 0x7f7f00, 0x7f007f, 0x007f7f};
	t_fork *temp = core->forks;
	if (i == 0)
	{
		while (temp)
		{
			if (pos == temp->curr_point)
				return (abs(temp->parent_id) < 7 ? colors[abs(temp->parent_id) - 1] : 0xff);
			temp = temp->next;
		}
	}
	else if (i == 1)
		return (abs((int)pos) < 7 ? colors1[abs((int)pos) - 1] : 0xffffff);
	return (0);
}

int ft_corewar(t_core *core)
{
    int i = 0;
	int j;
    int col;

    if (core->space && !(core->space && core->nxt))
	    return (0);//ft_print_info(core, 2));//print pause
	cycle(core);
	core->cycles_num++;
	if (core->proc)
	{
		mlx_clear_window(core->mlx_ptr, core->win_ptr);
		mlx_put_image_to_window(core->mlx_ptr, core->win_ptr, core->img_ptr_frame, 0, 0);
		print_players(core);
		ft_print_info(core, 1);
		while (++i < 65)
		{
			j = -1;
			while (++j < 64)
			{
				core->tab[0] = _HEXL[(int)core->map[(i - 1) * 64 + j] / 16];
				core->tab[1] = _HEXL[(int)core->map[(i - 1) * 64 + j] % 16];
				core->tab[2] = ' ';
				core->tab[3] = '\0';
				mlx_string_put(core->mlx_ptr, core->win_ptr, (j + 1) * 25, i * 18, (col = ft_check_curr(core, (i - 1) * 64 + j, 0)) ? col : core->map_col[(i - 1) * 64 + j], core->tab);
			}
		}
		core->nxt = 0;
		core->proc = 0;
	}
	return (0);
}

int		key_hook(int key, void *param)
{
	t_core *core;

	core = (t_core *)param;
	if (key == 53)
		exit(0);
	else if (key == 49)
		core->space = core->space ? 0 : 1;
	else if (key == 124)
		core->nxt = 1;
	return (0);
}

void    ft_visual(t_core *core)
{
    core->mlx_ptr = mlx_init();
	core->win_ptr = mlx_new_window(core->mlx_ptr, W, H, "corewar");
	ft_print_info(core, 0);
	ft_corewar1(core);
    mlx_hook(core->win_ptr, 2, 5, key_hook, (void *)core);
	mlx_loop_hook(core->mlx_ptr, ft_corewar, (void *)core);
	mlx_loop(core->mlx_ptr);
}


int ft_corewar1(t_core *core)
{
    int i = 0;
	int j;
    int col;

	while (++i < 65)
	{
		j = -1;
		while (++j < 64)
		{
			core->tab[0] = _HEXL[(int)core->map[(i - 1) * 64 + j] / 16];
			core->tab[1] = _HEXL[(int)core->map[(i - 1) * 64 + j] % 16];
			core->tab[2] = ' ';
            core->tab[3] = '\0';
            mlx_string_put(core->mlx_ptr, core->win_ptr, (j + 1) * 25, i * 18, (col = ft_check_curr(core, (i - 1) * 64 + j, 0)) ? col : core->map_col[(i - 1) * 64 + j], core->tab);
		}
	}
	return (0);
}