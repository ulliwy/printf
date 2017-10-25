/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:28:52 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/18 14:28:55 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdst;

	cdst = (char *)dst;
	csrc = (char *)src;
	if (cdst == csrc || len == 0)
		return (dst);
	while (len > 0)
	{
		if (cdst < csrc)
		{
			*cdst = *csrc;
			cdst++;
			csrc++;
			len--;
		}
		else
		{
			cdst[len - 1] = csrc[len - 1];
			len--;
		}
	}
	return (dst);
}
