/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:00:31 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 16:29:30 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int			usage(void)
{
	ft_printf("%s %s %s", "usage: ./corewar [-v] [-s] [-e] [-l]",
				"[-dump N]", "[[-n N] champion1.cor] ...\n");
	ft_printf("\t\t%-7{grn}s - visual output\n", "-v");
	ft_printf("\t\t%-7{grn}s - visual output step by step\n", "-s");
	ft_printf("\t\t%-7{grn}s - extended text output\n", "-e");
	ft_printf("\t\t%-7{grn}s - leaks\n", "-l");
	ft_printf("\t\t%-7{grn}s - game stops on N-th cycle %s", "-dump N",
			"(N > 0) and map is showed\n");
	ft_printf("\t\t%-7{grn}s - defines player's id (N != 0)\n", "-n N");
	return (0);
}

int			error(char *answer, t_core *core)
{
	exit(ft_printf("%{red}s\n", answer) + (_L));
	return (0);
}

void		create_name(t_header *player, int curr_pl)
{
	char	*s;
	char	*temp;

	ft_printf("%{red}s%{red}s\n", "Player's name is not defined, ",
			"creating something");
	s = ft_itoa(curr_pl);
	temp = ft_strjoin("Unknown player #", s);
	free(s);
	ft_strcpy(player->prog_name, temp);
}
