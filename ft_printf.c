/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:11:35 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/23 16:09:19 by iprokofy         ###   ########.fr       */
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
			if (fmt->prec < 0)
			{
				fmt->is_prec = 0;
				fmt->prec = 0;
			}
			(*s)++;
		}
	}
	return (1);
}

int		get_length(t_fmt *fmt, const char **s, va_list *valist)
{
	while (ft_isdigit(**s) || **s == '*')
	{
		fmt->length = 0;
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
	if (fmt->lajst && fmt->pad)
		fmt->pad = 0;
	return (1);
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
	int ret;

	ret = 0;
	if (fmt->lajst)
	{
		if (fmt->modifier != MOD_L)
		{
			ft_putchar(*((char *)c));
			ret++;
		}
		else
			ret += ft_putwchar(*((wchar_t *)c));
	}
	while (fmt->length > 1)
	{
		write(1, &(fmt->pad), 1);
		fmt->length--;
		ret++;
	}
	if (!fmt->lajst)
	{
		if (fmt->modifier != MOD_L)
		{
			ft_putchar(*((char *)c));
			ret++;
		}
		else
			ret += ft_putwchar(*((wchar_t *)c));
	}
	return (ret);
}

int		mod_charfmt(t_fmt *fmt, va_list *valist)
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
	return (ft_putchar_fmt((void *)(&c), fmt));
}

int		ft_putstr_fmt(void *c, t_fmt *fmt)
{
	int		to_print;
	int		spaces;
	int		len;

	if (!c && !fmt->is_prec)
	{
		ft_putstr("(null)");
		return (6);
	}
	//printf("this: \"%S\"\n", (wchar_t *)c);
	//printf("mod: %d\n", fmt->modifier == MOD_L);
	len = fmt->modifier == MOD_L ? ft_wstrlen((wchar_t *)c, fmt) : ft_strlen(c);
	//printf("len: %d\n", len);
	to_print = fmt->prec > len ? len : fmt->prec;
	//printf("to_print: %d\n", to_print);
	to_print = fmt->is_prec ? to_print : len;
	//printf("to_print: %d\n", to_print);
	spaces = fmt->length > to_print ? fmt->length - to_print : 0;
	len = spaces;
	//printf("spaces: %d\n", spaces);
	if (fmt->lajst)
	{
		if (fmt->modifier != MOD_L)
		{
			len += to_print;
			ft_putnstr(c, to_print);
		}
		else
			len += ft_putnwstr(c, to_print);
	}
	while (spaces)
	{
		write(1, &(fmt->pad), 1);
		spaces--;
	}
	if (!fmt->lajst)
	{
		if (fmt->modifier != MOD_L)
		{
			len += to_print;
			ft_putnstr(c, to_print);
		}
		else
			len += ft_putnwstr(c, to_print);
	}
	return (len);
}

int		mod_strfmt(t_fmt *fmt, va_list *valist)
{
	void	*c;

	if (fmt->type == 'S' || (fmt->type == 's' && fmt->modifier == MOD_L))
	{
		fmt->modifier = MOD_L;
		c = (wchar_t *)va_arg(*valist, void *);
	}
	else
		c = (char *)va_arg(*valist, void *);
	if (fmt->pad)
		fmt->pad = '0';
	else
		fmt->pad = ' ';
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
	while (nbr != 0)
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
	if (nbr == 0 || (fmt->altfm && (fmt->type == 'o' || fmt->type == 'O')))
		length++;
	if (nbr && fmt->altfm && (fmt->type == 'x' || fmt->type == 'X'))
		length = length + 2;
	//printf("len: %d\n", length);
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
	if (nbr && fmt->altfm && (fmt->type == 'o' || fmt->type == 'O'))
		ft_putchar('0');

	if (nbr && fmt->altfm && fmt->type == 'x')
		ft_putstr("0x");
	else if (nbr && fmt->altfm && fmt->type == 'X')
		ft_putstr("0X");

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
	//printf("digits: %d\n", digits);
	if (nbr < 0 || fmt->sign || fmt->space)
		sign++;
	if (fmt->is_prec)
		zeroes = digits > fmt->prec ? 0 : fmt->prec - digits;
	else if (fmt->pad)
		zeroes = fmt->length > digits + sign ? fmt->length - digits - sign : 0;
	spaces = fmt->length > digits + sign + zeroes ? fmt->length - digits - sign - zeroes : 0;
	sign = spaces + sign + zeroes + digits;
	//printf("digits: %d, spaces: %d, zeroes: %d\n", digits, spaces, zeroes);
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
	//printf("here 2: %d\n", fmt->is_prec);
	if (fmt->altfm && !nbr && !fmt->prec && (fmt->type == 'o' || fmt->type == 'O'))
	{
		fmt->prec = 1;
	}

	digits = (fmt->is_prec && !nbr) ? 0 : get_unbr_digits(nbr, fmt);
	//printf("digits %d\n", digits);
	if (fmt->is_prec)
		zeroes = digits > fmt->prec ? 0 : fmt->prec - digits;
	else if (fmt->pad)
		zeroes = fmt->length > digits ? fmt->length - digits : 0;
	spaces = fmt->length > digits + zeroes ? fmt->length - digits - zeroes : 0;
	//printf("digits: %d, spaces: %d, zeroes: %d\n", digits, spaces, zeroes);
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

void	get_hex(unsigned char *arr, char *c, int *first, t_fmt *fmt)
{
	int		i;
	int		j;

	//printf("%d\n", *arr);
	i = (int)sizeof(arr) - 1;
	//printf("%d\n", i);
	j = 2;
	c[0] = '0';
	c[1] = 'x';
	if (!(*arr) && !(fmt->is_prec && !fmt->prec))
		c[j++] = '0';
	if (fmt->is_prec && !fmt->prec)
		fmt->prec = 2;
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

int 	get_ptr_len(unsigned char *arr)
{
	int count;
	int i;
	int first;

	count = 0;
	first = 1;
	i = (int)sizeof(arr) - 1;
	while (*arr && i >= 0)
	{
		if (!(arr[i] / 16) && (arr[i] % 16) && first)
		{
			count++;
			first = 0;
		}
		else if (((arr[i] / 16) && (arr[i] % 16)) || !(first))
		{
			count = count + 2;
			first = 0;
		}
		i--;
	}
	return (count);
}

int		ft_putptr_fmt(void *c, t_fmt *fmt)
{
	unsigned char	*arr;
	int				len;
	int				first;
	int 			z;

	first = 1;
	arr = (unsigned char *)&c;
	len = get_ptr_len(arr);
	if (fmt->is_prec)
		z = fmt->prec > len ? fmt->prec - len : 0;

	//printf("len: %d\n", len);
	//get_hex(arr, str, &first, fmt);
	//printf("%s\n", str);
	//fmt->prec = 0;
	//fmt->modifier = 0;
	//printf("here: %s\n", str);
	return (len);
}

int		mod_ptrfmt(t_fmt *fmt, va_list *valist)
{
	void *c;

	c = va_arg(*valist, void *);
	if (fmt->pad)
		fmt->pad = '0';
	else
		fmt->pad = ' ';
	return (ft_putptr_fmt(c, fmt));
}

int		print_arg(t_fmt *fmt, va_list *valist)
{
	if (!fmt->type)
		return (-1);
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
	return (mod_charfmt(fmt, valist));
}

int		parse_arg(va_list *valist, const char **s)
{
	int		len;
	t_fmt	fmt;

	len = 0;
	//printf("\"%s\"\n", *s);
	(*s)++;
	//printf("\"%s\"\n", *s);
	if (!get_flags(&fmt, s))
		return (0);
	get_length(&fmt, s, valist);
	get_precision(&fmt, s, valist);
	get_modifier(&fmt, s);
	//print_struct(fmt);
	fmt.type = **s;
	//printf("type: \"%d\"\n", fmt.type);
	if ((len = print_arg(&fmt, valist)) == -1)
	{
		len = 0;
		(*s)--;
	}
	(*s)++;
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list		valist;
	int			len;
	int			temp;

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
		{
			temp = parse_arg(&valist, &format);
			if (temp == -1)
			{
				len = -1;
				break;
			}
			else
				len += temp;
		}
	}
	va_end(valist);
	return (len);
}
