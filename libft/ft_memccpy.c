/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 13:57:43 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/18 13:57:44 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	unsigned char	u_c;

	u_c = (unsigned char)c;
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	while (n > 0)
	{
		if (*csrc == u_c)
		{
			*cdst = u_c;
			cdst++;
			return (cdst);
		}
		*cdst = *csrc;
		cdst++;
		csrc++;
		n--;
	}
	return (NULL);
}
