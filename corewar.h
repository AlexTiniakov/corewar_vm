/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:01:13 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/20 16:01:15 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft/libft.h"
# include <fcntl.h>

void			init_players(t_header players[MAX_PLAYERS]);
int				read_player(int fd, t_header *player, int curr_pl);

void			init_fork(t_fork **fork, unsigned int id, unsigned int start,
		unsigned char optcode);

short			find_operation(char opcode);
int				find_player(t_header players[MAX_PLAYERS], unsigned int id);
unsigned int	find_num(unsigned char map[MEM_SIZE], unsigned int index,
		short size);

void			init_map(unsigned char map[MEM_SIZE]);
void			print_map(unsigned char map[MEM_SIZE]);

void			cycle(unsigned char map[MEM_SIZE], t_fork *forks,
		t_header players[MAX_PLAYERS]);

void			alive(unsigned char map[MEM_SIZE], t_fork **forks,
		t_header players[MAX_PLAYERS]);
void			load(unsigned char map[MEM_SIZE], t_fork **forks,
		t_header players[MAX_PLAYERS]);
void			store(unsigned char map[MEM_SIZE], t_fork **forks,
		t_header players[MAX_PLAYERS]);
void			addition(unsigned char map[MEM_SIZE], t_fork **forks,
		t_header players[MAX_PLAYERS]);
void			substract(unsigned char map[MEM_SIZE], t_fork **forks,
		t_header players[MAX_PLAYERS]);
void			anding(unsigned char map[MEM_SIZE], t_fork **forks,
		t_header players[MAX_PLAYERS]);
void			oring(unsigned char map[MEM_SIZE], t_fork **forks,
		t_header players[MAX_PLAYERS]);
void			xoring(unsigned char map[MEM_SIZE], t_fork **forks,
		t_header players[MAX_PLAYERS]);
void			jump(unsigned char map[MEM_SIZE], t_fork **forks,
		t_header players[MAX_PLAYERS]);
void			load_index(unsigned char map[MEM_SIZE], t_fork **forks,
		t_header players[MAX_PLAYERS]);
void			store_index(unsigned char map[MEM_SIZE], t_fork **forks,
		t_header players[MAX_PLAYERS]);
void			forking(unsigned char map[MEM_SIZE], t_fork **forks,
		t_header players[MAX_PLAYERS]);
void			long_load(unsigned char map[MEM_SIZE], t_fork **forks,
		t_header players[MAX_PLAYERS]);
void			long_load_index(unsigned char map[MEM_SIZE], t_fork **forks,
		t_header players[MAX_PLAYERS]);
void			long_forking(unsigned char map[MEM_SIZE], t_fork **forks,
		t_header players[MAX_PLAYERS]);
void			aff(unsigned char map[MEM_SIZE], t_fork **forks,
		t_header players[MAX_PLAYERS]);
#endif
