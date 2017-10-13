/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:11:35 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/13 16:40:01 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int 	get_precision(t_fmt *fmt, const char **s, va_list *valist)
{
	if (**s == '.')
	{
		(*s)++;
		if (ft_isdigit(**s))
		{
			while (ft_isdigit(**s))
			{
				fmt->prec = 10 * fmt->prec + (**s - '0');
				(*s)++;
			}
		}
		else if (**s == '*')
		{
			fmt->prec = va_arg(*valist, int);
			(*s)++;
		}
	}
	return (1);
}

int 		get_length(t_fmt *fmt, const char **s, va_list *valist)
{
	if (ft_isdigit(**s))
	{
		while (ft_isdigit(**s))
		{
			fmt->length = 10 * fmt->length + (**s - '0');
			(*s)++;
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
		(*s)++;
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
		(*s)++;
	}
	return (arg_analyze(fmt));
}

int 	get_modifier(t_fmt *fmt, const char **s)
{
	if (**s == 'h' && *(*s + 1) == 'h')
	{
		fmt->modifier = MOD_HH;
		(*s)++;
	}
	else if (**s == 'h')
		fmt->modifier = MOD_H;
	else if (**s == 'l' && *(*s + 1) == 'l')
	{
		fmt->modifier = MOD_LL;
		(*s)++;
	}
	else if (**s == 'l')
		fmt->modifier = MOD_L;
	else if (**s == 'j')
		fmt->modifier = MOD_J;
	else if (**s == 'z')
		fmt->modifier = MOD_Z;
	if (fmt->modifier)
		(*s)++;
	return (1);
}

int 	ft_putchar_fmt(void *c, t_fmt *fmt)
{
	if (fmt->sign || fmt->space || fmt->altfm || fmt->pad || fmt->prec)
		return (0);
	if (fmt->lajst)
		ft_putwchar_fmt(*((wchar_t *)c));
	while (fmt->length > 1)
	{
		write(1, " ", 1);
		fmt->length--;
	}
	if (!fmt->lajst)
		ft_putwchar_fmt(*((wchar_t *)c));
	printf("\n");
	printf("final1: %c\n", *((char *)c));
	printf("final2: %d\n", fmt->modifier);
	printf("----------------\n");
	return (1);
}

int		mod_charfmt(t_fmt *fmt, va_list *valist)
{
	int 	c;

	if (fmt->type == 'c' && fmt->modifier == 0)
		c = (unsigned char)va_arg(*valist, int);
	else if (fmt->type == 'C' || (fmt->type == 'c' && fmt->modifier == MOD_L))
		c = (wchar_t)va_arg(*valist, wint_t);
	else
		c = '%';
	return (ft_putchar_fmt((void *)(&c), fmt));
}

int 	ft_putstr_fmt(void *c, t_fmt fmt)
{
	printf("final1: %s\n", (char *)c);
	printf("final2: %d\n", fmt.modifier);
	printf("----------------\n");
	return (1);
}

int		mod_strfmt(t_fmt *fmt, va_list *valist)
{
	void		*c;

	if (fmt->type == 'S' || (fmt->type == 's' && fmt->modifier == MOD_L))
		c = (wchar_t *)va_arg(*valist, wchar_t *);
	else
		c = (char *)va_arg(*valist, void *);
	return (ft_putstr_fmt((void *)c, *fmt));
}

int 	ft_putnbr_fmt(void *c, t_fmt fmt)
{
	printf("final1: %d\n", *((int *)c));
	printf("final2: %d\n", fmt.modifier);
	printf("----------------\n");
	return (1);
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
	return (ft_putnbr_fmt((void *)(&c), *fmt));
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
	return (ft_putnbr_fmt((void *)(&c), *fmt));
}

int		mod_lintfmt(t_fmt *fmt, va_list *valist)
{
	long int c;

	c = (long int)va_arg(*valist, long int);
	return (ft_putnbr_fmt((void *)(&c), *fmt));
}

int 	ft_putptr_fmt(void *c, t_fmt fmt)
{
	printf("final1: %p\n", c);
	printf("final2: %d\n", fmt.modifier);
	printf("----------------\n");
	return (1);
}

int		mod_ptrfmt(t_fmt *fmt, va_list *valist)
{
	void *c;

	c = va_arg(*valist, void *);
	return (ft_putptr_fmt(c, *fmt));
}

int 	print_arg(t_fmt *fmt, va_list *valist)
{
	if (fmt->type == '%')
	 	return (mod_charfmt(fmt, valist));
	else if (fmt->type == 'c' || fmt->type == 'C')
	 	return (mod_charfmt(fmt, valist));
	else if (fmt->type == 's' || fmt->type == 'S')
	 	return (mod_strfmt(fmt, valist));
	else if (fmt->type == 'd' || fmt->type == 'i')
	  	return (mod_intfmt(fmt, valist));
	else if (fmt->type == 'o' || fmt->type == 'u' || fmt->type == 'x' || fmt->type == 'X')
	 	return (mod_uintfmt(fmt, valist));
	else if (fmt->type == 'D' || fmt->type == 'O' || fmt->type == 'U')
	 	return (mod_lintfmt(fmt, valist));
	else if (fmt->type == 'p')
	 	return (mod_ptrfmt(fmt, valist));
	return (0);
}

void 	print_struct(t_fmt fmt)
{
	printf("lajst: %d\n", fmt.lajst);
	printf("sign: %d\n", fmt.sign);
	printf("space: %d\n", fmt.space);
	printf("altfm: %d\n", fmt.altfm);
	printf("pad: %d\n", fmt.pad);
	printf("width: %d\n", fmt.width);
	printf("prec: %d\n", fmt.prec);
	printf("length: %d\n", fmt.length);
	printf("modifier: %d\n", fmt.modifier);
	printf("----\n");	
}

int 	parse_arg(va_list *valist, const char **s)
{
	int 	len;
	t_fmt	fmt;

	len = 0;
	(*s)++;
	if (!get_flags(&fmt, s))
		return (0);
	get_length(&fmt, s, valist);
	get_precision(&fmt, s, valist);
	get_modifier(&fmt, s);
	print_struct(fmt);
	fmt.type = **s;
	len = print_arg(&fmt, valist);
	(*s)++;
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
