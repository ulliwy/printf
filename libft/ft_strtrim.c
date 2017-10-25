/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:51:20 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/20 14:51:21 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	unsigned int	len;
	unsigned int	i;
	char			*new;

	if (!s)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
		s++;
	len = ft_strlen(s);
	i = len - 1;
	if (len > 0)
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i--;
	new = (char *)malloc(sizeof(char) * (i + 1 + 1));
	if (!new)
		return (NULL);
	len = 0;
	while (s[len] && len <= i)
	{
		new[len] = s[len];
		len++;
	}
	new[i + 1] = '\0';
	return (new);
}
