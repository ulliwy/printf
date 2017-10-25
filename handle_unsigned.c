/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:22:21 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/24 16:44:12 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_unbr_digits(unsigned long long int nbr, t_fmt *fmt)
{
	int div;
	int length;

	if (fmt->type == 'o' || fmt->type == 'O')
		div = 8;
	else if (fmt->type == 'x' || fmt->type == 'X')
		div = 16;
	else
		div = 10;
	length = 0;
	if (nbr == 0 || (fmt->altfm && (fmt->type == 'o' || fmt->type == 'O')))
		length++;
	if (nbr && fmt->altfm && (fmt->type == 'x' || fmt->type == 'X'))
		length = length + 2;
	while (nbr != 0)
	{
		length++;
		nbr = nbr / div;
	}
	return (length);
}

void	print_udigits(unsigned long long int nbr, int div, t_fmt *fmt)
{
	if (nbr == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (nbr >= (unsigned long long int)div)
	{
		print_udigits(nbr / div, div, fmt);
		if (fmt->type == 'x')
			ft_putchar(HEX[nbr % div]);
		else
			ft_putchar(HEXC[nbr % div]);
	}
	else if (fmt->type == 'x')
		ft_putchar(HEX[nbr % div]);
	else
		ft_putchar(HEXC[nbr % div]);
}

int		print_unbr(unsigned long long int nbr, t_fmt *fmt, int digits,
					int zeroes)
{
	int div;
	int ret;

	if (fmt->type == 'o' || fmt->type == 'O')
		div = 8;
	else if (fmt->type == 'x' || fmt->type == 'X')
		div = 16;
	else
		div = 10;
	if (nbr && fmt->altfm && (fmt->type == 'o' || fmt->type == 'O'))
		ft_putchar('0');
	if (nbr && fmt->altfm && fmt->type == 'x')
		ft_putstr("0x");
	else if (nbr && fmt->altfm && fmt->type == 'X')
		ft_putstr("0X");
	if (fmt->is_prec && nbr && fmt->prec && fmt->altfm && fmt->type == 'x')
		zeroes = fmt->prec - digits > 0 ? fmt->prec - digits : 0;
	ret = zeroes;
	while (zeroes--)
		ft_putchar('0');
	if (digits)
		print_udigits(nbr, div, fmt);
	return (ret);
}

int		ft_putunbr_fmt(void *c, t_fmt *fmt)
{
	unsigned long long int	nbr;
	int						digits;
	int						spaces;
	int						sign;
	int						zeroes;

	zeroes = 0;
	nbr = *((unsigned long long int *)c);
	digits = (fmt->is_prec && !nbr) ? 0 : get_unbr_digits(nbr, fmt);
	if (fmt->is_prec)
		zeroes = digits > fmt->prec ? 0 : fmt->prec - digits;
	else if (fmt->pad)
		zeroes = fmt->length > digits ? fmt->length - digits : 0;
	spaces = fmt->length > digits + zeroes ? fmt->length - digits - zeroes : 0;
	if (fmt->is_prec && fmt->prec && fmt->altfm && fmt->type == 'x')
		spaces = spaces - 2 > 0 ? spaces - 2 : 0;
	sign = spaces + digits;
	if (!fmt->lajst)
		while (spaces-- > 0)
			ft_putchar(' ');
	sign += print_unbr(nbr, fmt, digits, zeroes);
	if (fmt->lajst)
		while (spaces-- > 0)
			ft_putchar(' ');
	return (sign);
}

int		mod_uintfmt(t_fmt *fmt, va_list *valist)
{
	unsigned long long int c;

	if (fmt->modifier == MOD_HH)
		c = (unsigned char)va_arg(*valist, unsigned long long int);
	else if (fmt->modifier == MOD_H)
		c = (unsigned short)va_arg(*valist, unsigned long long int);
	else if (fmt->modifier == MOD_L)
		c = (unsigned long)va_arg(*valist, unsigned long long int);
	else if (fmt->modifier == MOD_LL)
		c = (unsigned long long)va_arg(*valist, unsigned long long int);
	else if (fmt->modifier == MOD_J)
		c = (uintmax_t)va_arg(*valist, unsigned long long int);
	else if (fmt->modifier == MOD_Z)
		c = (size_t)va_arg(*valist, unsigned long long int);
	else
		c = (unsigned int)va_arg(*valist, unsigned int);
	return (ft_putunbr_fmt((void *)(&c), fmt));
}
