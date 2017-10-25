/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:56:26 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/19 15:56:28 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	char	*little_start;
	int		steps;

	if (*little == '\0')
		return ((char *)big);
	little_start = (char *)little;
	steps = 0;
	while (*big && (steps < (int)len))
	{
		i = 0;
		while (*big == *little && (steps < (int)len))
		{
			if (*(little + 1) == '\0')
				return ((char *)(big - i));
			i++;
			big++;
			little++;
			steps++;
		}
		big = big - i + 1;
		little = little_start;
		steps = steps - i + 1;
	}
	return (NULL);
}
