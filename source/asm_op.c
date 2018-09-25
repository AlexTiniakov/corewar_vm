/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2018/09/23 15:04:59 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../op.h"
#include "../corewar.h"

t_op g_op_tab[18] =
{
	{0, 0, {0}, 0, 0, 0, 0, 0, NULL},
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 4, &alive},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 4, &load},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 4, &store},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 4, &addition},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 4, &substract},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 4, &anding},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 4, &oring},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 4, &xoring},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 2, &jump},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 2, &load_index},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 2, &store_index},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 2, &forking},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 4, &long_load},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 2, &long_load_index},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 2, &long_forking},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 4, &aff},
	{0, 0, {0}, 0, 0, 0, 0, 0, NULL}
};

/*
**{name, number_of_args, array_of_args, opcode, number_of_cycles,
**description, octal, label_size, pointer_on_function}
*/
