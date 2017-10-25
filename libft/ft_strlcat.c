/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 13:45:55 by iprokofy          #+#    #+#             */
/*   Updated: 2017/08/15 13:45:57 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	int				copied;

	i = 0;
	copied = 0;
	while (*dst && i < size)
	{
		dst++;
		i++;
	}
	while (*src)
	{
		if (i < size - 1 && size != 0)
		{
			*dst = *src;
			dst++;
			copied = 1;
		}
		src++;
		i++;
	}
	if (copied)
		*dst = '\0';
	return (i);
}
