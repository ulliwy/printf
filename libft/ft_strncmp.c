/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:25:15 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/19 16:25:17 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned int	u_i;

	i = 0;
	u_i = 0;
	while (u_i < n)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if ((*s1 == '\0' && *s1 != '\0') || (*s1 != '\0' && *s1 == '\0'))
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (!(*s1) && !(*s2))
			return (0);
		u_i++;
	}
	return ((unsigned char)(*(s1 - 1)) - (unsigned char)(*(s2 - 1)));
}
