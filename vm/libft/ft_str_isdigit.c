/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:15:03 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/27 20:30:28 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_isdigit(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (i == 0 && str[i] == '-')
			continue ;
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}
