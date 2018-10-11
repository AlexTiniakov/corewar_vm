/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_codage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 17:04:36 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 15:32:35 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		check_codage(unsigned int codage, int opcode)
{
	t_arg_type	code[MAX_ARGS_NUMBER];
	int			i;
	int			shift;
	int			flag;

	i = -1;
	flag = 0;
	shift = 2 * (MAX_ARGS_NUMBER - 1);
	while (++i < MAX_ARGS_NUMBER)
	{
		code[i] = (codage >> shift) & 3;
		shift -= 2;
		if (!g_op_tab[opcode].args[i] && !code[i])
			NULL;
		else if (g_op_tab[opcode].args[i] && !code[i])
			flag = 1;
		else if (!CHECK_BIT(g_op_tab[opcode].args[i],
						(code[i]) ? code[i] - 1 : 0))
			flag = 1;
	}
	return (flag);
}

void	make_shift(t_fork **fork, unsigned int shift,
		unsigned int arg)
{
	if (shift != 1 && arg && arg > 0 && arg < 17)
		(*fork)->carry = ((*fork)->registr[arg]) ? 0 : 1;
	(*fork)->curr_point += shift;
	(*fork)->curr_point %= MEM_SIZE;
}

int		select_params(t_core *core, t_fork **fork, unsigned int codage,
		unsigned int arg[3])
{
	int		result;
	int		shift;
	int		i;

	i = -1;
	shift = 6;
	result = 0;
	while (++i < 3)
	{
		if (((codage >> shift) & 3) == IND_CODE)
			arg[i] = find_num(core->map, (*fork)->curr_point + 2 + result, 2);
		else if (((codage >> shift) & 3) == DIR_CODE)
			arg[i] = find_num(core->map, (*fork)->curr_point + 2 + result, 4);
		else if (((codage >> shift) & 3) == REG_CODE)
			arg[i] = find_num(core->map, (*fork)->curr_point + 2 + result, 1);
		if (((codage >> shift) & 3) == IND_CODE)
			result += 2;
		else if (((codage >> shift) & 3) == DIR_CODE)
			result += 4;
		else if (((codage >> shift) & 3) == REG_CODE)
			result += 1;
		shift -= 2;
	}
	return (result);
}

int		check_regs(t_core *core, t_fork **fork, unsigned int codage,
		unsigned int arg[3])
{
	int		i;
	int		shift;

	i = -1;
	shift = 6;
	while (++i < 2)
	{
		if (((codage >> shift) & 3) == IND_CODE)
			arg[i] = find_num(core->map, ((*fork)->curr_point +
					(arg[i] % IDX_MOD) + MEM_SIZE) % MEM_SIZE, 4);
		else if (((codage >> shift) & 3) == REG_CODE &&
				(arg[i] == 0 || arg[i] > 16))
			return (1);
		else if (((codage >> shift) & 3) == REG_CODE &&
				(arg[i] != 0 && arg[i] < 17))
			arg[i] = (*fork)->registr[arg[i]];
		shift -= 2;
	}
	return (0);
}

/*
** reading {size} bytes from {fd} and turn them into a integer
*/

int		read_int(t_core *core, int fd, int size)
{
	unsigned char		buff[4];
	unsigned int		x;
	int					i;
	int					ex;

	ex = 1;
	x = 0;
	if (read(fd, buff, size) < size)
		error("error: Can't read more from file", core);
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
