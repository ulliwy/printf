/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:30:53 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/20 13:30:55 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*temp;
	int				len;
	char			*new;
	unsigned int	i;

	if (!s)
		return (NULL);
	temp = (char *)s;
	len = ft_strlen(s);
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	temp = new;
	i = 0;
	while (*s)
	{
		*new = f(i, *s);
		new++;
		s++;
		i++;
	}
	*new = '\0';
	return (temp);
}
