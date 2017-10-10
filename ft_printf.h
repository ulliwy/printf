/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 11:41:56 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/10 16:08:24 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

# include "libft/libft.h"

# define FUNC_ARR_SIZE 255


typedef struct 	s_out
{
	char		s;
	int			(*f)(void *);
}				t_out;

typedef struct	s_fmt
{
	int			lajst;	//'-'
	int			sign;	//'+' and ' ' -> 0:"default"; 1:"put sign, - or +"; -1:"only for signed, space for other"
	int			altfm;	//'#'
	int			pad;	//'0'
	int			width;	//field width
	int			prec;	//precision
	int			length;	//length modifier
}				t_fmt;

int				ft_printf(const char* format, ...);

int				ft_putchar_fmt(char c);
int				ft_putwchar_fmt(int c);
int				ft_putstr_fmt(char const *s);

int				ft_printnbr(int *nbr);


#endif
