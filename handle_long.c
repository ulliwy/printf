/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 13:03:37 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/25 13:18:58 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		mod_lintfmt(t_fmt *fmt, va_list *valist)
{
	long int			c;
	unsigned long int	uc;

	if (fmt->type == 'D')
	{
		c = (long)va_arg(*valist, long long int);
		return (ft_putnbr_fmt((void *)(&c), fmt));
	}
	else
	{
		uc = (unsigned long)va_arg(*valist, unsigned long long int);
		return (ft_putunbr_fmt((void *)(&uc), fmt));
	}
}
