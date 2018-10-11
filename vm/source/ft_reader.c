/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:02:52 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/28 20:23:38 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static int	check_flags(t_core *core)
{
	if (!ft_strcmp(core->av[core->index], "-dump"))
	{
		if (core->index < core->ac - 1 &&
				ft_str_isdigit(core->av[core->index + 1]) &&
				(core->dump = ft_atoi(core->av[core->index + 1])) > 0)
			return (2);
		else
			exit(usage() + (_L));
	}
	if (!ft_strcmp(core->av[core->index], "-v"))
		return (ABS(core->visual = 1));
	if (!ft_strcmp(core->av[core->index], "-s"))
		return (ABS(core->step = 1));
	if (!ft_strcmp(core->av[core->index], "-e"))
		return (ABS(core->extended = 1));
	if (!ft_strcmp(core->av[core->index], "-l"))
		return (ABS(core->leaks = 1));
	return (0);
}

static void	read_from_file(t_core *core)
{
	int				fd;

	if ((fd = open(core->av[core->index], O_RDWR)) < 0)
		error("error: Invalid file", core);
	if (core->pl_num >= MAX_PLAYERS)
		error("error: Too many players", core);
	if (read_player(fd, &(core->players[core->pl_num]), core->pl_num, core))
		error("error: Invalid player", core);
	else
		core->pl_num++;
	close(fd);
}

static int	skip_flags(t_core *core)
{
	int				fd;

	while ((fd = check_flags(core)))
	{
		if ((core->index += fd) >= core->ac)
			fd = -1;
		if (fd == -1)
			break ;
	}
	if (core->step)
		core->visual = 1;
	return (0);
}

int			reader(t_core *core)
{
	skip_flags(core);
	while (core->index < core->ac)
	{
		if (!ft_strcmp(core->av[core->index], "-n"))
		{
			if (core->index < core->ac - 1 &&
					ft_str_isdigit(core->av[core->index + 1]) &&
					(core->next_player_index =
						ft_atoi(core->av[core->index + 1])) != 0)
				core->index += 2;
			else
				exit(usage() + (_L));
		}
		read_from_file(core);
		core->index++;
	}
	core->pl_num ? 0 : error("error: No players", core);
	return (0);
}
