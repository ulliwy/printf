/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:23:44 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/20 15:23:46 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_size(char const *s, char c)
{
	int		i;
	int		only_spaces;

	i = 0;
	only_spaces = 0;
	if (!(*s))
		return (0);
	while (*s == c)
		s++;
	if (!(*s))
		only_spaces = 1;
	while (*s)
	{
		if ((*s == c) && !(*(s + 1) == c) && *(s + 1) != '\0')
		{
			i++;
		}
		s++;
	}
	if (i == 0 && only_spaces)
		return (0);
	return (i + 1);
}

static char	**get_arr(char const *s, char c, int arr_size, char **arr)
{
	int		i;
	int		len;

	i = 0;
	while (i < arr_size)
	{
		len = 0;
		while (*s && !(*s == c))
		{
			len++;
			s++;
		}
		if (!(arr[i] = (char *)malloc((len + 1) * sizeof(char))))
			return (NULL);
		arr[i] = ft_strncpy(arr[i], s - len, len);
		arr[i][len] = '\0';
		while (*s && *s == c)
			s++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		arr_size;

	if (!s)
		return (NULL);
	arr_size = calc_size(s, c);
	if (!(arr = (char **)malloc((arr_size + 1) * sizeof(char *))))
		return (NULL);
	while (*s == c)
		s++;
	return (get_arr(s, c, arr_size, arr));
}
