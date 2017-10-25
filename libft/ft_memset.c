/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:30:32 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/18 11:30:34 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	u_c;
	char			*str;
	unsigned char	i;

	str = (char *)b;
	u_c = c;
	i = 0;
	while (i < len)
	{
		if (len > 0)
			*str = u_c;
		else
			break ;
		str++;
		len--;
	}
	return (b);
}
