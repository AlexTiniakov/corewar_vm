/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:01:13 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/19 13:18:43 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft/libft.h"
# include <fcntl.h>

void		init_players(t_header players[MAX_PLAYERS]);
int			read_player(int fd, t_header *player);

void		init_fork(t_fork **fork, unsigned int id, unsigned int start,
		unsigned char optcode);

short		find_operation(char opcode);
int			find_player(t_header players[MAX_PLAYERS], unsigned int id);

void		init_map(unsigned char map[MEM_SIZE]);
void		print_map(unsigned char map[MEM_SIZE]);

void		cycles(unsigned char map[MEM_SIZE], t_fork *forks,
		t_header players[MAX_PLAYERS]);

#endif
