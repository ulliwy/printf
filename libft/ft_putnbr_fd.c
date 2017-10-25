/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:04:20 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/20 17:04:22 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u_nb;

	u_nb = n;
	if (u_nb == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 0)
	{
		u_nb = -u_nb;
		ft_putchar_fd('-', fd);
	}
	if (u_nb >= 10)
	{
		ft_putnbr_fd(u_nb / 10, fd);
		ft_putchar_fd(u_nb % 10 + '0', fd);
	}
	else
		ft_putchar_fd(u_nb + '0', fd);
}
