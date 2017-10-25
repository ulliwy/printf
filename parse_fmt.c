/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:04:46 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/24 14:11:46 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_precision(t_fmt *fmt, const char **s, va_list *valist)
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

int			get_modifier(t_fmt *fmt, const char **s)
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

int			get_length(t_fmt *fmt, const char **s, va_list *valist)
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

static void	fmt_init(t_fmt *fmt)
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

int			get_flags(t_fmt *fmt, const char **s)
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
