/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 21:12:06 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
**  OKOKOKOKOKOKOKOKOKOKOKOK
**  gets two indexes, adds them and writes from the map to register with
**  third index
**  tested, seems ok
*/

static void	extended_lldi(unsigned int arg[3], int codage)
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

void		long_load_index(t_core *core, t_fork **fork)
{
	unsigned int	codage;
	unsigned int	shift;
	unsigned int	arg[3];

	codage = find_num(core->map, (*fork)->curr_point + 1, 1);
	if (core->extended)
		ft_printf("%-4d||%5{grn}s||", (*fork)->curr_point, "lldi");
	shift = 1;
	if (!check_codage(codage, 14))
	{
		shift += 1 + select_params_li(core, fork, codage, arg);
		if (core->extended)
			extended_lldi(arg, codage);
		if (check_regs(core, fork, codage, arg) || (arg[2] <= 0 || arg[2] > 16))
			shift = 1;
		else
			(*fork)->registr[arg[2]] = find_num(core->map,
						((*fork)->curr_point + (int)(arg[0] + arg[1]) +
						MEM_SIZE) % MEM_SIZE, 4);
	}
	make_shift(fork, shift, arg[2]);
	if (core->extended)
		ft_putchar('\n');
}
