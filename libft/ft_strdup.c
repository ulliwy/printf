/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 15:37:27 by iprokofy          #+#    #+#             */
/*   Updated: 2017/08/16 15:37:30 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*p;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	p = str;
	while (*s1)
	{
		*p = *s1;
		p++;
		s1++;
	}
	*p = '\0';
	return (str);
}
