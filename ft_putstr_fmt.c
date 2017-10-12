/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:41:55 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/11 11:41:49 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_fmt(char const *s)
{
	int		count;

	count = 0;
	if (s)
		while (*s)
		{
			ft_putchar_fmt((void *)s);
			s++;
			count++;
		}
	return (count);
}
