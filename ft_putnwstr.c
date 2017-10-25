/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:11:41 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/24 13:08:43 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnwstr(wchar_t *str, int n)
{
	int				count;
	int				current;
	unsigned int	c;

	count = 0;
	if (str)
	{
		while (*str && n > 0)
		{
			c = (unsigned int)(*str);
			if ((c > 0x7F && c <= 0x7FF && n < 2) ||
				(c > 0x7FF && c <= 0x7FFFF && n < 3) ||
				(c > 0x7FFFF && c <= 0x10FFFF && n < 4))
				return (count);
			current = ft_putwchar(c);
			count += current;
			str++;
			n -= current;
		}
	}
	return (count);
}
