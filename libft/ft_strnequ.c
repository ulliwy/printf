/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:58:08 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/20 13:58:10 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char	i;

	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	i = 0;
	while (*s1 && i < n)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
		i++;
	}
	if (*s1 != *s2 && i < n)
		return (0);
	return (1);
}
