/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 21:19:17 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
** OKOKOKOKOKOKOK
**	takes three params, first and second can be or reg or dir or ind,
**  and makes ^  with first and second values into registr wtih third index
**  need more tests, seems ok
*/

static void	extended_xoring(unsigned int arg[3], int codage)
{
	int		shift;
	int		i;
	int		result;
	char	*s[3];

	shift = 6;
	result = 0;
	i = -1;
	while (++i < 3)
	{
		if (((codage >> shift) & 3) == IND_CODE)
			s[i] = "";
		else if (((codage >> shift) & 3) == DIR_CODE)
			s[i] = "%";
		else if (((codage >> shift) & 3) == REG_CODE)
			s[i] = "r";
		shift -= 2;
	}
	ft_printf("%s%d %s%d %s%d||", s[0], arg[0], s[1], arg[1], s[2], arg[2]);
}

void		xoring(t_core *core, t_fork **fork)
{
	unsigned int	shift;
	unsigned int	codage;
	unsigned int	arg[3];

	codage = find_num(core->map, (*fork)->curr_point + 1, 1);
	if (core->extended)
		ft_printf("%-4d||%5{grn}s||", (*fork)->curr_point, "xor");
	shift = 1;
	if (!check_codage(codage, 8))
	{
		shift += 1 + select_params(core, fork, codage, arg);
		if (core->extended)
			extended_xoring(arg, codage);
		if (check_regs(core, fork, codage, arg) || arg[2] <= 0 || arg[2] > 16)
			shift = 1;
		else
			(*fork)->registr[arg[2]] = arg[0] ^ arg[1];
	}
	make_shift(fork, shift, arg[2]);
	if (core->extended)
		ft_putchar('\n');
}
