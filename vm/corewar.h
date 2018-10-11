/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:01:13 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 11:07:42 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <time.h>

# define W 2150
# define H 1193
# define INFO 1680
# define TAB 15
# define LP 70
# define LP1 90
# define LP2 105
# define Y 140
# define DY 20
# define CENTER 1850
# define MLX core->mlx_ptr, core->win_ptr

# define LEAK system("leaks -q corewar")
# define _L (core->leaks ? LEAK : 0)
# define CD (core->extended)

int				reader(t_core *core);

t_core			*init_core(t_core *core, int ac, char **av);
void			init_players(t_header players[MAX_PLAYERS]);
int				read_player(int fd, t_header *player, int curr_pl,
		t_core *core);

/*
** working with forks
*/
void			init_fork(t_fork **fork, unsigned int id, unsigned int start,
		unsigned char optcode);
void			copy_fork(t_fork *father, t_fork **fork, unsigned int sd);

/*
** required for every operation functions
*/
int				check_codage(unsigned int codage, int opcode);
void			make_shift(t_fork **fork, unsigned int shift,
		unsigned int arg);
int				select_params(t_core *core, t_fork **fork, unsigned int codage,
		unsigned int arg[3]);
int				check_regs(t_core *core, t_fork **fork, unsigned int codage,
		unsigned int arg[3]);
int				read_int(t_core *core, int fd, int size);

int				select_params_li(t_core *core, t_fork **fork,
		unsigned int codage, unsigned int arg[3]);

/*
** functions to search something
*/
int				find_player(t_header players[MAX_PLAYERS], unsigned int id);
unsigned int	find_num(unsigned char map[MEM_SIZE], unsigned int index,
		short size);

/*
** map handling
*/
void			init_map(unsigned char map[MEM_SIZE]);
int				print_map(unsigned char map[MEM_SIZE]);
void			print_reg1(t_core *core, unsigned int index,
		unsigned int argument, int id);

int				cycle(t_core *core);

/*
** operation functions
*/
void			alive(t_core *core, t_fork **fork);
void			load(t_core *core, t_fork **fork);
void			store(t_core *core, t_fork **fork);
void			addition(t_core *core, t_fork **fork);
void			substract(t_core *core, t_fork **fork);
void			anding(t_core *core, t_fork **fork);
void			oring(t_core *core, t_fork **fork);
void			xoring(t_core *core, t_fork **fork);
void			jump(t_core *core, t_fork **fork);
void			load_index(t_core *core, t_fork **fork);
void			store_index(t_core *core, t_fork **fork);
void			forking(t_core *core, t_fork **fork);
void			long_load(t_core *core, t_fork **fork);
void			long_load_index(t_core *core, t_fork **fork);
void			long_forking(t_core *core, t_fork **fork);
void			aff(t_core *core, t_fork **fork);

/*
** error management
*/
int				error(char *answer, t_core *core);
int				usage(void);
void			create_name(t_header *player, int curr_pl);

/*
** visualizator
*/
int				spin_visual(t_core *core);

void			ft_put_white(t_core *core);
int				ft_check_curr(t_core *core, unsigned int pos, int i);
void			print_forks(t_fork *forks);
int				check_ids(t_core *core, unsigned int id);

void			ft_visual(t_core *core);

int				ft_term(t_core *core);

int				ft_print_info(t_core *core, int i);

int				ft_put_frame(t_core *core);

void			ft_print_winner(t_core *core);

void			print_players(t_core *core);

int				ft_cycle(t_core *core);
int				ft_print_pause(t_core *core, int i, int j, int col);

void			checkout(t_core *core);

void			ft_print_lines(t_core *core);

void			ft_print_winner(t_core *core);

void			header_validation(t_core *core);

#endif
