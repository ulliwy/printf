/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:11:35 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/18 11:11:38 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		get_precision(t_fmt *fmt, const char **s, va_list *valist)
{
	if (**s == '.')
	{
		fmt->is_prec = 1;
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

int		get_length(t_fmt *fmt, const char **s, va_list *valist)
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

void	fmt_init(t_fmt *fmt)
{
	fmt->lajst = 0;
	fmt->sign = 0;
	fmt->space = 0;
	fmt->altfm = 0;
	fmt->pad = 0;
	fmt->prec = 0;
	fmt->is_prec = 0;
	fmt->length = 0;
	fmt->modifier = 0;
}

int		arg_analyze(t_fmt *fmt)
{
	if (fmt->lajst && fmt->space)
		return (0);
	if (fmt->lajst && fmt->pad)
		return (0);
	return (1);
}

int		get_flags(t_fmt *fmt, const char **s)
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
			break ;
		(*s)++;
	}
	return (arg_analyze(fmt));
}

int		get_modifier(t_fmt *fmt, const char **s)
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

int		ft_putchar_fmt(void *c, t_fmt *fmt)
{
	if (fmt->sign || fmt->space || fmt->altfm || fmt->pad || fmt->prec)
		return (0);
	if (fmt->lajst)
		ft_putwchar(*((wchar_t *)c));
	while (fmt->length > 1)
	{
		write(1, " ", 1);
		fmt->length--;
	}
	if (!fmt->lajst)
		ft_putwchar(*((wchar_t *)c));
	return (1);
}

int		mod_charfmt(t_fmt *fmt, va_list *valist)
{
	int		c;

	if (fmt->type == 'c' && fmt->modifier == 0)
		c = (unsigned char)va_arg(*valist, int);
	else if (fmt->type == 'C' || (fmt->type == 'c' && fmt->modifier == MOD_L))
		c = (wchar_t)va_arg(*valist, wint_t);
	else
		c = '%';
	return (ft_putchar_fmt((void *)(&c), fmt));
}

int		ft_putstr_fmt(void *c, t_fmt *fmt)
{
	int		to_print;
	int		spaces;
	int		len;

	len = fmt->modifier == MOD_L ? ft_wstrlen(c) : ft_strlen(c);
	to_print = fmt->prec > len ? len : fmt->prec;
	to_print = fmt->prec ? to_print : len;
	spaces = fmt->length > to_print ? fmt->length - to_print : 0;
	len = to_print + spaces;
	if (fmt->lajst)
		fmt->modifier == MOD_L ? ft_putnwstr(c, to_print) :
										ft_putnstr(c, to_print);
	while (spaces)
	{
		write(1, " ", 1);
		spaces--;
	}
	if (!fmt->lajst)
		fmt->modifier == MOD_L ? ft_putnwstr(c, to_print) :
										ft_putnstr(c, to_print);
	return (len);
}

int		mod_strfmt(t_fmt *fmt, va_list *valist)
{
	void	*c;

	if (fmt->type == 'S' || (fmt->type == 's' && fmt->modifier == MOD_L))
		c = (wchar_t *)va_arg(*valist, wchar_t *);
	else
		c = (char *)va_arg(*valist, void *);
	return (ft_putstr_fmt((void *)c, fmt));
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
	while (nbr / div != 0)
	{
		length++;
		nbr = nbr / div;
	}
	return (length);
}

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
	if (nbr == 0)
		length++;
	while (nbr != 0)
	{
		//printf("nbr: %llu\n", nbr);
		length++;
		nbr = nbr / div;
	}
	return (length);
}

void	print_struct(t_fmt fmt)
{
	printf("lajst: %d\n", fmt.lajst);
	printf("sign: %d\n", fmt.sign);
	printf("space: %d\n", fmt.space);
	printf("altfm: %d\n", fmt.altfm);
	printf("pad: %d\n", fmt.pad);
	printf("prec: %d\n", fmt.prec);
	printf("length: %d\n", fmt.length);
	printf("modifier: %d\n", fmt.modifier);
	printf("----\n");
}

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
	else
		if (fmt->type == 'x')
			ft_putchar(HEX[u_nb % div]);
		else
			ft_putchar(HEXC[u_nb % div]);
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
		print_digits(nbr / div, div, fmt);
		if (fmt->type == 'x')
			ft_putchar(HEX[nbr % div]);
		else
			ft_putchar(HEXC[nbr % div]);
	}
	else
		if (fmt->type == 'x')
			ft_putchar(HEX[nbr % div]);
		else
			ft_putchar(HEXC[nbr % div]);
}

void		print_nbr(long long int nbr, t_fmt *fmt, int digits, int zeroes)
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
	while(zeroes--)
		ft_putchar('0');
	if (digits)
		print_digits(nbr, div, fmt);
}

void		print_unbr(unsigned long long int nbr, t_fmt *fmt, int digits, int zeroes)
{
	int div;

	if (fmt->type == 'o' || fmt->type == 'O')
		div = 8;
	else if (fmt->type == 'x' || fmt->type == 'X')
		div = 16;
	else
		div = 10;
	while(zeroes--)
		ft_putchar('0');
	if (digits)
		print_udigits(nbr, div, fmt);
}

int		ft_putnbr_fmt(void *c, t_fmt *fmt)
{
	long long int	nbr;
	int				digits;
	int				spaces;
	int 			sign;
	int 			zeroes;

	sign = 0;
	zeroes = 0;
	nbr = *((long long int *)c);
	digits = (fmt->is_prec && !nbr) ? 0 : get_nbr_digits(nbr, fmt);
	if (nbr < 0 || fmt->sign || fmt->space)
		sign++;
	if (fmt->is_prec)
		zeroes = digits > fmt->prec ? 0 : fmt->prec - digits;
	else if (fmt->pad)
		zeroes = fmt->length > digits + sign ? fmt->length - digits - sign : 0;
	spaces = fmt->length > digits - sign - zeroes ? fmt->length - digits - sign - zeroes : 0;
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

int		ft_putunbr_fmt(void *c, t_fmt *fmt)
{
	unsigned long long int	nbr;
	int						digits;
	int						spaces;
	int 					sign;
	int 					zeroes;

	zeroes = 0;
	nbr = *((unsigned long long int *)c);
	//printf("here 2: %llu\n", nbr);
	digits = (fmt->is_prec && !nbr) ? 0 : get_unbr_digits(nbr, fmt);
	//printf("digits %d\n", digits);
	if (fmt->is_prec)
		zeroes = digits > fmt->prec ? 0 : fmt->prec - digits;
	else if (fmt->pad)
		zeroes = fmt->length > digits ? fmt->length - digits : 0;
	spaces = fmt->length > digits - zeroes ? fmt->length - digits - zeroes : 0;
	sign = spaces + zeroes + digits;
	if (!fmt->lajst)
		while (spaces-- > 0)
			ft_putchar(' ');
	print_unbr(nbr, fmt, digits, zeroes);
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
	//printf("here: %llu\n", c);
	return (ft_putunbr_fmt((void *)(&c), fmt));
}

int		mod_lintfmt(t_fmt *fmt, va_list *valist)
{
	long int c;
	unsigned long int uc;

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

void	get_hex(unsigned char *arr, char *c, int *first)
{
	int		i;
	int		j;

	i = (int)sizeof(arr) - 1;
	j = 2;
	c[0] = '0';
	c[1] = 'x';
	if (!(*arr))
		c[j++] = '0';
	while (*arr && i >= 0)
	{
		if (!(arr[i] / 16) && (arr[i] % 16) && *first)
		{
			c[j++] = HEX[arr[i] % 16];
			*first = 0;
		}
		else if (((arr[i] / 16) && (arr[i] % 16)) || !(*first))
		{
			c[j++] = HEX[arr[i] / 16];
			c[j++] = HEX[arr[i] % 16];
			*first = 0;
		}
		i--;
	}
	c[j] = '\0';
}

int		ft_putptr_fmt(void *c, t_fmt *fmt)
{
	unsigned char	*arr;
	char			*str;
	int				len;
	int				first;

	first = 1;
	arr = (unsigned char *)&c;
	str = (char *)malloc((int)sizeof(arr) * 2 + 3);
	get_hex(arr, str, &first);
	fmt->prec = 0;
	len = ft_putstr_fmt(str, fmt);
	free(str);
	return (len);
}

int		mod_ptrfmt(t_fmt *fmt, va_list *valist)
{
	void *c;

	c = va_arg(*valist, void *);
	return (ft_putptr_fmt(c, fmt));
}

int		print_arg(t_fmt *fmt, va_list *valist)
{
	if (fmt->type == '%')
		return (mod_charfmt(fmt, valist));
	else if (fmt->type == 'c' || fmt->type == 'C') //done
		return (mod_charfmt(fmt, valist));
	else if (fmt->type == 's' || fmt->type == 'S') //done
		return (mod_strfmt(fmt, valist));
	else if (fmt->type == 'd' || fmt->type == 'i') //done
		return (mod_intfmt(fmt, valist));
	else if (fmt->type == 'o' || fmt->type == 'u' || fmt->type == 'x'
												|| fmt->type == 'X')
		return (mod_uintfmt(fmt, valist));
	else if (fmt->type == 'D' || fmt->type == 'O' || fmt->type == 'U')
		return (mod_lintfmt(fmt, valist));
	else if (fmt->type == 'p') //done
		return (mod_ptrfmt(fmt, valist)); 
	return (0);
}

int		parse_arg(va_list *valist, const char **s)
{
	int		len;
	t_fmt	fmt;

	len = 0;
	(*s)++;
	if (!get_flags(&fmt, s))
		return (0);
	get_length(&fmt, s, valist);
	get_precision(&fmt, s, valist);
	get_modifier(&fmt, s);
	//print_struct(fmt);
	fmt.type = **s;
	len = print_arg(&fmt, valist);
	(*s)++;
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list		valist;
	int			len;

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
