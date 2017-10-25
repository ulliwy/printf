/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:11:35 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/24 15:03:27 by iprokofy         ###   ########.fr       */
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
	//printf("len: %d\n", length);
	while (nbr != 0)
	{
		//printf("nbr: %llu\n", nbr);
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
	else
		if (fmt->type == 'x')
			ft_putchar(HEX[nbr % div]);
		else
			ft_putchar(HEXC[nbr % div]);
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
	//printf("%d\n", fmt->altfm);
	if (fmt->is_prec && fmt->prec && fmt->altfm && fmt->type == 'x')
	{
		zeroes = zeroes + 2;
		spaces = spaces - 2 > 0 ? spaces - 2 : 0;
	}
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

void	get_hex(unsigned char *arr, t_fmt *fmt)
{
	int		i;
	int 	first;

	//printf("%d\n", *arr);
	first = 1;
	i = (int)sizeof(arr) - 1;
	while (i >= 0)
	{
		//printf("here\n");
		if (!(arr[i] / 16) && (arr[i] % 16) && first)
		{
			ft_putchar(HEX[arr[i] % 16]);
			first = 0;
		}
		else if (((arr[i] / 16) && (arr[i] % 16)) || !(first))
		{
			ft_putchar(HEX[arr[i] / 16]);
			ft_putchar(HEX[arr[i] % 16]);
			first = 0;
		}
		//printf("%d\n", first);
		i--;
	}
	if (first && !(fmt->is_prec && !fmt->prec))
	 	ft_putchar('0');
}

int 	get_ptr_len(unsigned char *arr, t_fmt *fmt)
{
	int count;
	int i;
	int first;

	count = 0;
	first = 1;
	i = (int)sizeof(arr) - 1;
	while (i >= 0)
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
	//printf("%d\n", first);
	if (first && !(fmt->is_prec && !fmt->prec))
	 	return (1);
	return (count);
}

int		ft_putptr_fmt(void *c, t_fmt *fmt)
{
	unsigned char	*arr;
	int				len;
	int 			z;
	int 			count;
	int 			pad;

	arr = (unsigned char *)&c;
	len = get_ptr_len(arr, fmt);
	//printf("len: %d\n", len);
	z = 0;
	if (fmt->is_prec)
		z = fmt->prec > len ? fmt->prec - len : 0;
	//printf("z: %d\n", z);
	count = len + z;
	if (fmt->length > z + len + 2)
		fmt->length = fmt->length - z - len - 2;
	else
		fmt->length = 0;
	pad = fmt->length;
	//printf("length: %d\n", fmt->length);
	count = count + fmt->length + 2;
	while (!fmt->lajst && fmt->length && fmt->pad != '0')
	{
		ft_putchar(fmt->pad);
		fmt->length--;
	}
	write(1, "0x", 2);
	//printf("pad: %d\n", pad);
	while (!fmt->is_prec && fmt->pad == '0' && pad--)
		ft_putchar('0');
	while (z--)
		ft_putchar('0');
	get_hex(arr, fmt);
	while (fmt->lajst && fmt->length)
	{
		ft_putchar(fmt->pad);
		fmt->length--;
	}
	return (count);
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
	else if (fmt->type == 'c' || fmt->type == 'C')
		return (mod_charfmt(fmt, valist));
	else if (fmt->type == 's' || fmt->type == 'S')
		return (mod_strfmt(fmt, valist));
	else if (fmt->type == 'd' || fmt->type == 'i')
		return (mod_intfmt(fmt, valist));
	else if (fmt->type == 'o' || fmt->type == 'u' || fmt->type == 'x'
												|| fmt->type == 'X')
		return (mod_uintfmt(fmt, valist));
	else if (fmt->type == 'D' || fmt->type == 'O' || fmt->type == 'U')
		return (mod_lintfmt(fmt, valist));
	else if (fmt->type == 'p')
		return (mod_ptrfmt(fmt, valist));
	return (mod_charfmt(fmt, valist));
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
	fmt.type = **s;
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
				return (-1);
			else
				len += temp;
		}
	}
	va_end(valist);
	return (len);
}
