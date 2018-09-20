/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:03:21 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/20 15:44:22 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		init_players(t_header players[MAX_PLAYERS])
{
	int i;
	int j;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		players[i].magic = 0;
		players[i].id = 0;
		players[i].prog_size = 0;
		j = -1;
		while (++j <= PROG_NAME_LENGTH + 1)
			players[i].prog_name[j] = 0;
		j = -1;
		while (++j <= COMMENT_LENGTH + 1)
			players[i].comment[j] = 0;
		j = -1;
		while (++j <= CHAMP_MAX_SIZE)
			players[i].program[j] = 0;
	}
}

static int	read_int(int fd, int size)
{
	unsigned char		buff[4];
	unsigned int		x;
	int					i;
	int					ex;

	ex = 1;
	x = 0;
	read(fd, buff, size);
	i = size;
	while (--i >= 0)
	{
		x += ex * (buff[i] % 16);
		ex *= 16;
		x += ex * (buff[i] / 16);
		ex *= 16;
	}
	return (x);
}

static void	read_info(int fd, t_header *player)
{
	int				i;
	unsigned char	buf[4];

	i = -1;
	while (++i < PROG_NAME_LENGTH)
	{
		read(fd, buf, 1);
		player->prog_name[i] = buf[0];
	}
	read(fd, buf, 4);
	player->prog_size = read_int(fd, 4);
	i = -1;
	while (++i < COMMENT_LENGTH)
	{
		read(fd, buf, 1);
		player->comment[i] = buf[0];
	}
	read(fd, buf, 4);
}

static void	read_code(int fd, t_header *player)
{
	unsigned int	i;
	unsigned char	buf[2];

	i = 0;
	while (i < player->prog_size)
	{
		read(fd, buf, 1);
		player->program[i] = buf[0];
		i++;
	}
	player->alive = 0;
}

int			read_player(int fd, t_header *player, int curr_pl)
{
	unsigned int	magic;
	int				i;

	if ((magic = read_int(fd, 4)) != COREWAR_EXEC_MAGIC)
		return (1);
	else
		player->magic = magic;
	i = -1;
	while (++i < REG_NUMBER)
		player->registr[i] = 0;
	read_info(fd, player);
	read_code(fd, player);
	player->id = 0xFFFFFFFF - curr_pl;
	player->registr[0] = player->id;
	return (0);
}
