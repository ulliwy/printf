/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 11:41:56 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/24 15:23:31 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft/libft.h"

# define FUNC_ARR_SIZE	255
# define MOD_H			1
# define MOD_HH			2
# define MOD_L			3
# define MOD_LL			4
# define MOD_J			5
# define MOD_Z			6

# define HEX			"0123456789abcdef"
# define HEXC			"0123456789ABCDEF"

typedef struct	s_out
{
	char		s;
	int			(*f)(void *);
}				t_out;

typedef struct	s_fmt
{
	int			lajst;
	int			sign;
	int			space;
	int			altfm;
	int			pad;
	int			prec;
	int			is_prec;
	int			length;
	int			modifier;
	int			type;
}				t_fmt;

int				ft_printf(const char *format, ...);

int				get_flags(t_fmt *fmt, const char **s);
int				get_length(t_fmt *fmt, const char **s, va_list *valist);
int				get_precision(t_fmt *fmt, const char **s, va_list *valist);
int				get_modifier(t_fmt *fmt, const char **s);

int				mod_charfmt(t_fmt *fmt, va_list *valist);
int				mod_strfmt(t_fmt *fmt, va_list *valist);
int				mod_intfmt(t_fmt *fmt, va_list *valist);
int				mod_uintfmt(t_fmt *fmt, va_list *valist);

int				ft_putnbr_fmt(void *c, t_fmt *fmt);

int				ft_putwchar(wchar_t c);
size_t			ft_wstrlen(const wchar_t *str, t_fmt *fmt);
int				ft_putnstr(char *c, int n);
int				ft_putnwstr(wchar_t *c, int n);

#endif
