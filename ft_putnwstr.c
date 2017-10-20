/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:11:41 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/19 11:37:58 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnwstr(wchar_t *c, int n)
{
	int 	count;

	count = 0;
	if (c)
		while (*c && n)
		{
			ft_putwchar(*c);
			c++;
			n--;
			count++;
		}
	return (count);
}	