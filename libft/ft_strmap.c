/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:28:26 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/20 13:28:28 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*temp;
	int		len;
	char	*new;

	if (!s)
		return (NULL);
	temp = (char *)s;
	len = 0;
	while (*temp)
	{
		len++;
		temp++;
	}
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	temp = new;
	while (*s)
	{
		*new = f(*s);
		new++;
		s++;
	}
	*new = '\0';
	return (temp);
}
