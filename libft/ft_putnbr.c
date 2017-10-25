/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:49:21 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/20 16:49:23 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int				buff[10];
	int				i;
	unsigned int	u_nb;

	if (n == 0)
		ft_putchar('0');
	u_nb = n;
	if (n < 0)
	{
		u_nb = -u_nb;
		ft_putchar('-');
	}
	i = 0;
	while (u_nb != 0)
	{
		buff[i] = (u_nb % 10);
		u_nb = u_nb / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(buff[i] + '0');
		i--;
	}
}
