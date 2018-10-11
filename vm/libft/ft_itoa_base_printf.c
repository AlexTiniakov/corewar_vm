/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 11:04:07 by dskrypny          #+#    #+#             */
/*   Updated: 2018/09/21 18:23:42 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	make_printf(size_t value, size_t base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789abcdef";
	if (value >= base)
		make_printf(value / base, base, str, i);
	str[(*i)++] = tmp[ABS(value % base)];
}

char	*ft_itoa_base_printf(size_t value, size_t base)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(32);
	make_printf(value, base, str, &i);
	str[i] = '\0';
	return (str);
}
