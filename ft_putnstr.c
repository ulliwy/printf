/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:52:28 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/26 13:28:07 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnstr(char *c, int n, int unicode)
{
	int		count;

	count = 0;
	if (c)
		while (*c && n)
		{
			if (unicode)
				ft_putwchar(*c);
			else
				ft_putchar(*c);
			c++;
			n--;
			count++;
		}
	return (count);
}
