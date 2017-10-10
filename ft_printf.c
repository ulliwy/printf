/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:11:35 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/10 16:21:14 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			fmt_init(t_fmt *fmt)
{
	fmt->altfm = 0;
	fmt->lajst = 0;
	fmt->sign = 0;
	fmt->pad = 0;
	return (1);
}

int			get_sign(const char *s, t_fmt *fmt)
{
	int 	i;

	i = 1;
	while (*s)
	{
		if (*s == '#')
			fmt->altfm = 1;
		else if (*s == '-')
			fmt->lajst = 1;
		else if (*s == '+')
			fmt->sign = 1;
		else if (*s == ' ')
		{
			if (fmt->sign)
				return (0);
			else
				fmt->sign = -1;
		}
		else
			return (i);
		i++;
		s++;
	}
	return (i);
}

int		ft_printf(const char* format, ...)
{
	va_list		valist;
	int			i;
	t_fmt		*fmt;

	va_start(valist, format);
	i = 0;
	fmt = (t_fmt *)malloc(sizeof(t_fmt));
	fmt_init(fmt);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			format++;
			i++;
			continue;
		}
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				ft_putchar(*format);
				format++;
				i++;
				continue;
			}
			
			format += get_sign(format, fmt) - 1
			get_fmt()

		}
		else
			break;
	}
	return (0);
}