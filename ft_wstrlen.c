/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:41:47 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/19 16:58:30 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wstrlen(const wchar_t *str)
{
	unsigned int	c;
	unsigned long	*counter;

	counter = 0;
	while (str && *str)
	{
		c = (unsigned int)(*str);
		if (c <= 0x7F)
			counter++;
		else if (c <= 0x7FF)
			counter += 2;
		else if (c <= 0x7FFFF)
			counter += 3;
		else if (c <= 0x10FFFF)
			counter += 4;
		str++;
	}
	return (counter);
}