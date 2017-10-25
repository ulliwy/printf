/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:37:01 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/20 14:37:03 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	char			*new_start;

	if (!s1 || !s2)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	new_start = new;
	while (*s1)
	{
		*new = *s1;
		new++;
		s1++;
	}
	while (*s2)
	{
		*new = *s2;
		new++;
		s2++;
	}
	*new = '\0';
	return (new_start);
}
