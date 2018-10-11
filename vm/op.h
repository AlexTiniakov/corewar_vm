/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2018/09/28 20:22:30 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4 * 1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				15

typedef char					t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		(0xea83f3)

# define _HEXU "0123456789ABCDEF"
# define _HEXL "0123456789abcdef"

/*
** struct for players
*/

typedef struct					s_header
{
	unsigned int				id;
	unsigned int				alive;
	unsigned int				magic;
	int							strlen;
	int							live_num;
	int							last_live;
	int							hole_game_live_num;
	unsigned int				prog_size;
	unsigned int				start;
	int							nb_proc;
	char						prog_name[PROG_NAME_LENGTH + 1];
	char						comment[COMMENT_LENGTH + 1];
	unsigned char				program[CHAMP_MAX_SIZE];
}								t_header;

/*
** n_args - how many arguments
** opcode - 0x01 - 0X10 || binary from table
** label_size - 0 == 4,  1 == 2
*/

/*
** struct for forks, which proceed war
*/
typedef struct s_fork			t_fork;

struct							s_fork
{
	char						alive;
	int							live_num;
	char						carry;
	short						opcode;
	int							parent_id;
	unsigned int				curr_point;
	unsigned int				cycles_to_wait;
	unsigned int				registr[REG_NUMBER + 1];
	t_fork						*next;
};

/*
** general structure
*/
typedef struct					s_core
{
	int							leaks : 1;
	int							space : 1;
	int							visual : 1;
	int							nxt : 1;
	int							proc : 1;
	int							play : 1;
	int							pause : 1;
	int							extended : 1;
	int							step : 1;
	int							dump;
	void						*mlx_ptr;
	void						*win_ptr;
	void						*img_ptr_frame;
	char						*frame;
	int							frame_color_num;
	int							frame_color;
	unsigned char				map[MEM_SIZE];
	int							map_col[MEM_SIZE];
	t_header					players[MAX_PLAYERS];
	t_fork						*forks;
	char						tab[4];
	int							ac;
	char						**av;
	int							index;
	int							pl_num;
	int							proc_num;
	int							last_live;
	int							players_live;
	int							next_player_index;
	long long					cycles_num;
	long long					cycles_to_die;
	long long					cycles_delta;
	long long					checkups;
}								t_core;

/*
** struct for operations
*/
typedef struct					s_op
{
	char						*instruct;
	unsigned short int			n_args;
	t_arg_type					args[MAX_ARGS_NUMBER];
	unsigned char				opcode;
	unsigned int				cycles;
	char						*desc;
	unsigned char				codage;
	unsigned char				label_size;
	void						(*operation)(t_core *, t_fork **fork);
}								t_op;

extern t_op						g_op_tab[18];

#endif
