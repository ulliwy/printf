/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:26:32 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/19 15:26:34 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	char	*little_start;

	if (*little == '\0')
		return ((char *)big);
	little_start = (char *)little;
	while (*big)
	{
		i = 0;
		while (*big == *little)
		{
			if (*(little + 1) == '\0')
				return ((char *)(big - i));
			i++;
			big++;
			little++;
		}
		big = big - i + 1;
		little = little_start;
	}
	return (NULL);
}
