/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:15:55 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/25 16:53:24 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_char(void *c, t_fmt *fmt)
{
	if (fmt->modifier != MOD_L)
	{
		ft_putchar(*((char *)c));
		return (1);
	}
	else
	{
		ft_putchar(*((char *)c));
		return (1);
	}
	//return (ft_putwchar(*((wchar_t *)c)));
}

int			ft_putchar_fmt(void *c, t_fmt *fmt)
{
	int ret;

	ret = 0;
	if (fmt->lajst)
		ret += print_char(c, fmt);
	while (fmt->length > 1)
	{
		write(1, &(fmt->pad), 1);
		fmt->length--;
		ret++;
	}
	if (!fmt->lajst)
		ret += print_char(c, fmt);
	return (ret);
}

int			mod_charfmt(t_fmt *fmt, va_list *valist)
{
	int		c;

	if (fmt->type == 'c' && fmt->modifier == 0)
		c = (unsigned char)va_arg(*valist, int);
	else if (fmt->type == 'C' || (fmt->type == 'c' && fmt->modifier == MOD_L))
	{
		fmt->modifier = MOD_L;
		c = (wchar_t)va_arg(*valist, wint_t);
	}
	else
		c = fmt->type;
	if (fmt->pad)
		fmt->pad = '0';
	else
		fmt->pad = ' ';
	if (fmt->modifier == MOD_L && c > 255)
		return (-1);
	return (ft_putchar_fmt((void *)(&c), fmt));
}
