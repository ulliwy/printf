/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:41:47 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/24 14:01:04 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(unsigned int c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0x7FFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	return (0);
}

size_t		ft_wstrlen(const wchar_t *str, t_fmt *fmt)
{
	unsigned int	c;
	unsigned long	counter;
	unsigned long	current;
	int				limit;

	counter = 0;
	limit = 0;
	while (str && *str)
	{
		c = (unsigned int)(*str);
		current = get_size(c);
		if (!limit && fmt->is_prec && (int)(counter + current) > fmt->prec)
		{
			fmt->prec = counter;
			limit = 1;
		}
		counter += current;
		str++;
	}
	return (counter);
}
