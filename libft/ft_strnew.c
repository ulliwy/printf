/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:12:07 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/20 13:12:08 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*new;
	unsigned int	i;

	new = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	if (new)
	{
		while (i < size + 1)
		{
			new[i] = '\0';
			i++;
		}
	}
	return (new);
}
