/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:54:15 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/20 11:59:37 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wrapper(unsigned int octet)
{
	if (octet == 0)
		return ;
	wrapper(octet / 2);
	ft_putchar(octet % 2 + '0');
}

void	print_bits(unsigned int octet)
{

	wrapper(octet);
}