/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 12:50:23 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/24 14:00:47 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putbigwchar(unsigned int c)
{
	if (c <= 0x7FFFF)
	{
		ft_putchar((c >> 12) + 224);
		ft_putchar(((c >> 6) & 63) + 128);
		ft_putchar((c & 63) + 128);
		return (3);
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar((c >> 18) + 240);
		ft_putchar(((c >> 12) & 63) + 128);
		ft_putchar(((c >> 6) & 63) + 128);
		ft_putchar((c & 63) + 128);
		return (4);
	}
	return (0);
}

int			ft_putwchar(wchar_t c)
{
	unsigned int	uc;

	uc = (unsigned int)c;
	if (uc <= 0x7F)
	{
		ft_putchar(uc);
		return (1);
	}
	else if (c <= 0x7FF)
	{
		ft_putchar((uc >> 6) + 192);
		ft_putchar((uc & 63) + 128);
		return (2);
	}
	else
		return (ft_putbigwchar(uc));
}
