/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:11:35 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/25 16:28:26 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		//len = 0;
		//(*s)--;
		return (len);
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
