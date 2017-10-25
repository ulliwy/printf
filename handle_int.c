/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:59:59 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/24 15:22:39 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_digits(long long int nbr, int div, t_fmt *fmt)
{
	unsigned long long int	u_nb;

	u_nb = (unsigned long long int)nbr;
	if (u_nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (nbr < 0)
		u_nb = -u_nb;
	if (u_nb >= (unsigned long long int)div)
	{
		print_digits(u_nb / div, div, fmt);
		if (fmt->type == 'x')
			ft_putchar(HEX[u_nb % div]);
		else
			ft_putchar(HEXC[u_nb % div]);
	}
	else if (fmt->type == 'x')
		ft_putchar(HEX[u_nb % div]);
	else
		ft_putchar(HEXC[u_nb % div]);
}

void	print_nbr(long long int nbr, t_fmt *fmt, int digits, int zeroes)
{
	int div;

	if (fmt->type == 'o' || fmt->type == 'O')
		div = 8;
	else if (fmt->type == 'x' || fmt->type == 'X')
		div = 16;
	else
		div = 10;
	if (nbr < 0 || fmt->sign || fmt->space)
	{
		if (nbr < 0)
			write(1, "-", 1);
		else if (fmt->sign)
			write(1, "+", 1);
		else if (fmt->space)
			write(1, " ", 1);
	}
	while (zeroes--)
		ft_putchar('0');
	if (digits)
		print_digits(nbr, div, fmt);
}

int		get_nbr_digits(long long int nbr, t_fmt *fmt)
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
	if (nbr == 0)
		length++;
	while (nbr != 0)
	{
		length++;
		nbr = nbr / div;
	}
	return (length);
}

int		ft_putnbr_fmt(void *c, t_fmt *fmt)
{
	long long int	nbr;
	int				digits;
	int				spaces;
	int				sign;
	int				zeroes;

	zeroes = 0;
	nbr = *((long long int *)c);
	digits = (fmt->is_prec && !nbr) ? 0 : get_nbr_digits(nbr, fmt);
	sign = nbr < 0 || fmt->sign || fmt->space;
	if (fmt->is_prec)
		zeroes = digits > fmt->prec ? 0 : fmt->prec - digits;
	else if (fmt->pad)
		zeroes = fmt->length > digits + sign ? fmt->length - digits - sign : 0;
	spaces = fmt->length > digits + sign + zeroes ?
									fmt->length - digits - sign - zeroes : 0;
	sign = spaces + sign + zeroes + digits;
	if (!fmt->lajst)
		while (spaces-- > 0)
			ft_putchar(' ');
	print_nbr(nbr, fmt, digits, zeroes);
	if (fmt->lajst)
		while (spaces-- > 0)
			ft_putchar(' ');
	return (sign);
}

int		mod_intfmt(t_fmt *fmt, va_list *valist)
{
	long long int c;

	if (fmt->modifier == MOD_HH)
		c = (signed char)va_arg(*valist, long long int);
	else if (fmt->modifier == MOD_H)
		c = (short)va_arg(*valist, long long int);
	else if (fmt->modifier == MOD_L)
		c = (long)va_arg(*valist, long long int);
	else if (fmt->modifier == MOD_LL)
		c = (long long)va_arg(*valist, long long int);
	else if (fmt->modifier == MOD_J)
		c = (intmax_t)va_arg(*valist, long long int);
	else if (fmt->modifier == MOD_Z)
		c = (size_t)va_arg(*valist, long long int);
	else
		c = (int)va_arg(*valist, int);
	return (ft_putnbr_fmt((void *)(&c), fmt));
}
