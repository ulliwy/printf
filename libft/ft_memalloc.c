/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:07:28 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/20 13:07:30 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;
	unsigned int	i;

	i = 0;
	mem = (unsigned char *)malloc(size);
	if (mem)
	{
		while (i < size)
		{
			mem[i] = 0;
			i++;
		}
	}
	return ((void *)mem);
}
