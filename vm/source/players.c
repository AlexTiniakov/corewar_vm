/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:03:21 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 23:02:34 by dskrypny         ###   ########.fr       */
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

/*
** reading name and comment
*/

static int	check_nulll(int fd, t_core *core, short x)
{
	int				i;
	unsigned char	buf[4];

	if (read(fd, buf, 4) < 4)
		error("There is no NULL after name", core);
	i = -1;
	while (++i < 4)
		if (buf[i])
			(x == 1) ? error("After name is not NULL!", core) :
				error("After comment is not NULL!", core);
	return (0);
}

static void	read_info(int fd, t_header *player, int curr_pl, t_core *core)
{
	int				i;
	unsigned char	buf[4];

	i = -1;
	while (++i < PROG_NAME_LENGTH)
	{
		if (read(fd, buf, 1) <= 0)
			error("error: Program's name is too small!", core);
		player->prog_name[i] = buf[0];
	}
	if (player->prog_name[0] == 0)
		create_name(player, curr_pl);
	check_nulll(fd, core, 1);
	if ((player->prog_size = read_int(core, fd, 4)) <= 0)
		error("", core);
	i = -1;
	while (++i < COMMENT_LENGTH)
	{
		if (read(fd, buf, 1) <= 0)
			error("error: Program's comment is too small!", core);
		player->comment[i] = buf[0];
	}
	check_nulll(fd, core, 0);
}

/*
** reading body of the player
*/

static void	read_code(int fd, t_header *player, t_core *core)
{
	unsigned int	i;
	unsigned char	buf[2];

	i = 0;
	if (player->prog_size > CHAMP_MAX_SIZE)
		error("error: Player's code is too big!", core);
	while (i < player->prog_size)
	{
		if (read(fd, buf, 1) <= 0)
			error("error: Program's size doesn't match with prog_size!", core);
		player->program[i] = buf[0];
		i++;
	}
	if (read(fd, buf, 1))
		error("error: Program's size doesn't match with prog_size!", core);
	player->alive = 0;
}

int			read_player(int fd, t_header *player, int curr_pl, t_core *core)
{
	unsigned int	magic;
	unsigned int	id;

	id = (core->next_player_index) ? core->next_player_index :
		0xFFFFFFFF - curr_pl;
	if ((magic = read_int(core, fd, 4)) != COREWAR_EXEC_MAGIC)
		error("error: Invalid magic header!", core);
	if (check_ids(core, id))
		error("error: Duplicate id!", core);
	player->magic = magic;
	player->live_num = 0;
	player->last_live = 0;
	player->hole_game_live_num = 0;
	player->id = id;
	player->strlen = ft_count_int(id);
	player->nb_proc = 1;
	read_info(fd, player, curr_pl, core);
	read_code(fd, player, core);
	core->next_player_index = 0;
	return (0);
}
