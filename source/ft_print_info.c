/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:31:43 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/25 12:31:44 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void    print_players(t_core *core)
{
    int     i;
    char    *s;

    i = -1;
    mlx_string_put(core->mlx_ptr, core->win_ptr, 1700, 100, 0x8E8177,
        "Champions:");   
    while (core->players[++i].magic && i < MAX_PLAYERS)
    {
        mlx_string_put(core->mlx_ptr, core->win_ptr, 1700, 120 + i * 100, 0x8E8177,
        "Player");
        s = ft_itoa((int)core->players[i].id);
        mlx_string_put(core->mlx_ptr, core->win_ptr, 1800, 120 + i * 100, 0x8E8177,
        s);
        free(s);
        mlx_string_put(core->mlx_ptr, core->win_ptr, 1705, 140 + i * 100, 0x8E8177,
        core->players[i].prog_name);       
    }
}

int ft_put_frame(t_core *core)
{
    int bpp;
    int sl;
    int end;
    int i, j;

    core->img_ptr_frame = mlx_new_image(core->mlx_ptr, W, H);
    core->frame = mlx_get_data_addr(core->img_ptr_frame, &bpp, &sl, &end);
    i = -1;
    while (++i < W)
    {
        j = -1;
        while (++j < 10)
        {
            core->frame[(i * 4 + sl * j)] = core->frame_color % 256;
            core->frame[(i * 4 + sl * j) + 1] = core->frame_color / 256 % 256;
            core->frame[(i * 4 + sl * j) + 2] = core->frame_color / 256 / 256 % 256;
        }
    }
    i = -1;
    while (++i < 10)
    {
        j = 9;
        while (++j < H - 10)
        {
            core->frame[(i * 4 + sl * j)] = core->frame_color % 256;
            core->frame[(i * 4 + sl * j) + 1] = core->frame_color / 256 % 256;
            core->frame[(i * 4 + sl * j) + 2] = core->frame_color / 256 / 256 % 256;
            core->frame[((i + 1633) * 4 + sl * j)] = core->frame_color % 256;
            core->frame[((i + 1633) * 4 + sl * j) + 1] = core->frame_color / 256 % 256;
            core->frame[((i + 1633) * 4 + sl * j) + 2] = core->frame_color / 256 / 256 % 256;
            core->frame[((i + W - 10) * 4 + sl * j)] = core->frame_color % 256;
            core->frame[((i + W - 10) * 4 + sl * j) + 1] = core->frame_color / 256 % 256;
            core->frame[((i + W - 10) * 4 + sl * j) + 2] = core->frame_color / 256 / 256 % 256;
        }
    }
    ft_memcpy(&core->frame[W * H * 4 - 40 * W], core->frame, 40 * W);
    mlx_put_image_to_window(core->mlx_ptr, core->win_ptr, core->img_ptr_frame, 0, 0);
    print_players(core);
    return (0);
}

int     ft_print_info(t_core *core, int i)
{
    static int colors[] = {0x150063, 0x9116AD, 0xFFFFFF};

    core->frame_color = colors[core->frame_color_num];
    if (!i)
        return (ft_put_frame(core));
    char *s = ft_itoa(core->cycles_num);
    mlx_string_put(core->mlx_ptr, core->win_ptr, 1700, 50, 0x8E8177, s);
    free(s); 
    return (0);
}