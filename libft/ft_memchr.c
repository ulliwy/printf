/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:14:15 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/18 15:14:18 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	unsigned char	u_c;

	cs = (unsigned char *)s;
	u_c = c;
	while (n > 0)
	{
		if (*cs == u_c)
			return (cs);
		cs++;
		n--;
	}
	return (NULL);
}
