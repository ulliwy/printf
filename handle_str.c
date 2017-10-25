/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:43:18 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/25 15:48:12 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_str(t_fmt *fmt, void *c, int to_print)
{
	if (fmt->modifier != MOD_L)
	{
		ft_putnstr(c, to_print);
		return (to_print);
	}
	else
	{
		ft_putnstr(c, to_print);
		return (to_print);
	}
	//return (ft_putnwstr(c, to_print));
}

int			ft_putstr_fmt(void *c, t_fmt *fmt)
{
	int		to_print;
	int		spaces;
	int		len;

	if (!c && !fmt->is_prec)
	{
		ft_putstr("(null)");
		return (6);
	}
	//len = fmt->modifier == MOD_L ? ft_wstrlen((wchar_t *)c, fmt) : ft_strlen(c);
	len = ft_strlen(c);
	to_print = fmt->prec > len ? len : fmt->prec;
	to_print = fmt->is_prec ? to_print : len;
	spaces = fmt->length > to_print ? fmt->length - to_print : 0;
	len = spaces;
	if (fmt->lajst)
		len += print_str(fmt, c, to_print);
	while (spaces)
	{
		write(1, &(fmt->pad), 1);
		spaces--;
	}
	if (!fmt->lajst)
		len += print_str(fmt, c, to_print);
	return (len);
}

int			mod_strfmt(t_fmt *fmt, va_list *valist)
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
