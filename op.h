/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2018/09/13 20:03:54 by dskrypny         ###   ########.fr       */
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
# define MEM_SIZE				(4*1024)
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
# define MAX_CHECKS				10

typedef char					t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					3
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		(0xea83f3)

typedef struct					s_header
{
	unsigned int		id;
	unsigned int		magic;
	unsigned int		prog_size;
	unsigned int		start;
	char				prog_name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	unsigned char		program[CHAMP_MAX_SIZE];
}								t_header;

/*
** n_args - how many arguments
** opcode - 0x01 - 0X10 || binary from table
** label_size - 0 == 4,  1 == 2
*/

typedef struct					s_op
{
	char						*instruct;
	unsigned short int			n_args;
	t_arg_type					args[MAX_ARGS_NUMBER];
	unsigned char				opcode;
	unsigned int				cycles;
	char						*desc;
	unsigned char				octal;
	unsigned char				label_size;
}								t_op;

typedef struct					s_fork
{
	char						alive;
	char						carry;
	char						optcode;
	char						parent_id;
	unsigned int				curr_point;
	unsigned int				cycles_to_wait;
	unsigned int				registr[16];
}								t_fork;

extern t_op						g_op_tab[17];

#endif