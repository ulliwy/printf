/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 12:11:26 by iprokofy          #+#    #+#             */
/*   Updated: 2017/08/14 12:11:28 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int	i;
	char			*ret;

	i = 0;
	ret = dst;
	while (i < len && *src)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	while (i < len && *dst)
	{
		*dst = '\0';
		i++;
		dst++;
	}
	return (ret);
}
