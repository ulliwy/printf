/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:52:28 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/16 14:54:51 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnstr(char *c, int n)
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