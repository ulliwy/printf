/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 11:41:56 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/13 16:08:02 by iprokofy         ###   ########.fr       */
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

typedef struct 	s_out
{
	char		s;
	int			(*f)(void *);
}				t_out;

typedef struct	s_fmt
{
	int			lajst;	//'-'
	int			sign;	//'+' and ' ' -> 0:"default"; 1:"put sign, - or +"; -1:"only for signed, space for other"
	int			space;
	int			altfm;	//'#'
	int			pad;	//'0'
	int			width;	//field width
	int			prec;	//precision
	int			length;	//length modifier
	int			modifier;
	int 		type;
}				t_fmt;

int				ft_printf(const char* format, ...);

#endif
