/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:08:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 21:15:11 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

/*
** OKOKOKOKOKOKOKOKOKOKOK
** reads three indexes and add values from registers with first and second
** indexes into register with third index
** tested ok
*/

static void	extended_addition(t_fork *fork, unsigned int arg[3])
{
	ft_printf("%-4d||%5{grn}s||r%d r%d r%d||\n", fork->curr_point, "add",
			arg[0], arg[1], arg[2]);
}

void		addition(t_core *core, t_fork **fork)
{
	unsigned int	arg[3];
	unsigned int	shift;
	unsigned int	codage;

	codage = find_num(core->map, (*fork)->curr_point + 1, 1);
	arg[0] = find_num(core->map, (*fork)->curr_point + 2, 1);
	arg[1] = find_num(core->map, (*fork)->curr_point + 3, 1);
	arg[2] = find_num(core->map, (*fork)->curr_point + 4, 1);
	shift = 1;
	if (!check_codage(codage, 4))
		if (arg[0] > 0 && arg[0] < 17 && arg[1] > 0 && arg[1] < 17 &&
				arg[2] > 0 && arg[2] < 17)
		{
			(*fork)->registr[arg[2]] = (*fork)->registr[arg[0]] +
				(*fork)->registr[arg[1]];
			shift = 5;
		}
	if (core->extended)
		extended_addition(*fork, arg);
	make_shift(fork, shift, arg[2]);
}

/*
**	char *s = ft_itoa_base(codage, 2);
**	ft_printf("%{red}s %{grn}d %s %s\n", "codage", codage, s,
**		(check_codage(codage, 4)) ? "not ok" : "ok");
**	free(s);
** 	ft_printf("addition!\n");
*/
