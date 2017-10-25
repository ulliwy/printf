/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:51:52 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/20 15:51:53 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_reverse(char *str)
{
	char *left;
	char *right;
	char temp;

	if (!str || *str == 0)
		return (str);
	left = str;
	right = left + ft_strlen(str) - 1;
	while (left < right)
	{
		temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
	return (str);
}

static char	*ft_border(char *str, int n)
{
	if (n == 0)
		return (ft_strcpy(str, "0"));
	return (ft_strcpy(str, "-2147483648"));
}

static int	get_size(int n)
{
	int		size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static char	*get_str(int n, char *str)
{
	while (n != 0)
	{
		*str = n % 10 + '0';
		n = n / 10;
		str++;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		neg;
	char	*str_start;

	neg = 0;
	if (!(str = (char *)malloc(sizeof(char) * (get_size(n) + 1))))
		return (NULL);
	str_start = str;
	if (n == 0 || n == -2147483648)
		return (ft_border(str, n));
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	str = get_str(n, str);
	if (neg)
	{
		*str = '-';
		str++;
	}
	*(str) = '\0';
	return (ft_reverse(str_start));
}
