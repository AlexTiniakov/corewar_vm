/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:00:31 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/23 14:25:38 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int			usage(void)
{
	return (ft_printf("%s %s", "usage: ./corewar [-dump nbr_cycles]",
				"[[-n number] champion1.cor] ...\n"));
}

int			error(char *answer)
{
	exit(ft_printf("%{red}s\n", answer));
	return (0);
}
