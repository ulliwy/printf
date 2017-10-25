/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:03:56 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/20 14:03:58 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	size;
	char			*new;
	char			*new_start;

	if (!s || start > (size = ft_strlen(s)) || start + len > size + 1)
		return (NULL);
	new = (char *)malloc(len * sizeof(char) + 1);
	if (!new)
		return (NULL);
	size = 0;
	new_start = new;
	while (*s)
	{
		if (size >= start && size < start + len)
		{
			*new = *s;
			new++;
		}
		s++;
		size++;
	}
	*new = '\0';
	return (new_start);
}
