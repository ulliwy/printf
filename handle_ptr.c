/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 11:38:45 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/25 15:28:07 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_hex(unsigned char *arr, t_fmt *fmt)
{
	int		i;
	int		first;

	first = 1;
	i = (int)sizeof(arr) - 1;
	while (i >= 0)
	{
		if (!(arr[i] / 16) && (arr[i] % 16) && first)
		{
			ft_putchar(HEX[arr[i] % 16]);
			first = 0;
		}
		else if (((arr[i] / 16)) || !(first))
		{
			ft_putchar(HEX[arr[i] / 16]);
			ft_putchar(HEX[arr[i] % 16]);
			first = 0;
		}
		i--;
	}
	if (first && !(fmt->is_prec && !fmt->prec))
		ft_putchar('0');
}

int		get_ptr_len(unsigned char *arr, t_fmt *fmt)
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
		else if (((arr[i] / 16))|| !(first))
		{
			count = count + 2;
			first = 0;
		}
		i--;
	}
	if (first && !(fmt->is_prec && !fmt->prec))
		return (1);
	return (count);
}

void	print_ptr(t_fmt *fmt, int pad, int z, unsigned char *arr)
{
	while (!fmt->lajst && fmt->length && fmt->pad != '0')
	{
		ft_putchar(fmt->pad);
		fmt->length--;
	}
	write(1, "0x", 2);
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
}

int		ft_putptr_fmt(void *c, t_fmt *fmt)
{
	unsigned char	*arr;
	int				len;
	int				z;
	int				count;
	int				pad;

	arr = (unsigned char *)&c;
	len = get_ptr_len(arr, fmt);
	z = 0;
	if (fmt->is_prec)
		z = fmt->prec > len ? fmt->prec - len : 0;
	count = len + z;
	if (fmt->length > z + len + 2)
		fmt->length = fmt->length - z - len - 2;
	else
		fmt->length = 0;
	pad = fmt->length;
	count = count + fmt->length + 2;
	print_ptr(fmt, pad, z, arr);
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
