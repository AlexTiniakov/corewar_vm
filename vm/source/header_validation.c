/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:54:10 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/27 21:54:19 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	header_validation(t_core *core)
{
	if (IND_SIZE <= 0 || REG_SIZE <= 0 || DIR_SIZE <= 0)
		error("Invalid size of size definitions", core);
	if (MEM_SIZE <= 0)
		error("Invalid size of size definitions", core);
	if (CYCLE_TO_DIE <= 0)
		error("Invalid cycle to die number", core);
	if (CYCLE_DELTA <= 0)
		error("Invalid cycle delta number", core);
	if (NBR_LIVE <= 0)
		error("Invalid NBR_LIVE number", core);
	if (MAX_CHECKS <= 0)
		error("Invalid maximum check's number", core);
	if (PROG_NAME_LENGTH <= 0)
		error("Invalid size of program's name in header", core);
	if (COMMENT_LENGTH <= 0)
		error("Invalid size of commen't length in header", core);
}
