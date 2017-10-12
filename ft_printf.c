/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:11:35 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/11 16:49:22 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// int 		get_flag(const char *s, t_fmt *fmt)
// {
// 	int i;

// 	i = 0;
// 	if (*s == 'h')
// 	{
// 		s++;
// 		i++;
// 		if (*s == 'h')
// 		{
// 			fmt->uchar = 1;
// 			i++;
// 		}
// 		else
// 			fmt->shrt = 1;
// 	}
// 	else if (*s == 'l')
// 	{
// 		s++;
// 		i++;
// 		if (*s == 'l')
// 		{
// 			fmt->lnglng = 1;
// 			i++;
// 		}
// 		else
// 			fmt->lng = 1;
// 	}
// 	else if (*s == 'j')
// 	{
// 		i++;
// 		fmt->intmax = 1;
// 	}
// 	else if (*s == 'z')
// 	{
// 		i++;
// 		fmt->sz = 1;
// 	}
// 	return (i);
// }

int 		get_precision(const char *s, t_fmt *fmt, va_list *valist)
{
	int 	i;

	i = 0;
	if (*s == '.')
	{
		if (ft_isdigit(*s))
		{
			while (ft_isdigit(*s))
			{
				fmt->prec = 10 * fmt->prec + (*s - '0');
				s++;
				i++;
			}
		}
		else if (*s == '*')
		{
			fmt->prec = va_arg(*valist, int);
			i++;
		}
	}
	return (i);
}


int 		get_length(t_fmt *fmt, const char **s, va_list *valist)
{
	if (ft_isdigit(**s))
	{
		while (ft_isdigit(**s))
		{
			fmt->length = 10 * fmt->length + (**s - '0');
			*s++;
		}
	}
	else if (**s == '*')
	{
		fmt->length = va_arg(*valist, int);
		if (fmt->length < 0)
		{
			fmt->lajst = !fmt->lajst;
			fmt->length = -fmt->length;
		}
		*s++;
	}
	return (1);
}

void		fmt_init(t_fmt *fmt)
{
	fmt->lajst = 0;
	fmt->sign = 0;
	fmt->space = 0;
	fmt->altfm = 0;
	fmt->pad = 0;
	fmt->width = 0;
	fmt->prec = 0;
	fmt->length = 0;
	fmt->modifier = 0;
}

int 	arg_analyze(t_fmt *fmt)
{
	if (fmt->lajst && fmt->space)
		return (0);
	if (fmt->lajst && fmt->pad)
		return (0);
	return (1);
}

int 	get_flags(t_fmt *fmt, const char **s)
{
	fmt_init(fmt);
	while (1)
	{
		if (**s == '-')
			fmt->lajst = 1;
		else if (**s == '+')
			fmt->sign = 1;
		else if (**s == ' ')
			fmt->space = 1;
		else if (**s == '#')
			fmt->altfm = 1;
		else if (**s == '0')
			fmt->pad = 1;
		else
			break;
		*s++;
	}
	return (arg_analyze(fmt));
}

int 	parse_arg(va_list *valist, const char **s)
{
	int 	len;
	t_fmt	fmt;

	len = 0;
	*s++;
	if (!get_flags(&fmt, s))
		return (0);
	get_length(&fmt, s, valist);
	get_precision(&fmt, s, valist);
	//len = print_arg(fmt, valist);
	return (len);
}

int		ft_printf(const char* format, ...)
{
	va_list		valist;
	int 		len;

	len = 0;
	va_start(valist, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			format++;
			len++;
		}
		else
			len += parse_arg(&valist, &format);
	}
	va_end(valist);
	return (len);
}
