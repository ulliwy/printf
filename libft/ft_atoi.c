/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:29:56 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/28 15:00:19 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	go_atoi(const char *str, int sign)
{
	long	value;
	long	temp;

	value = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (sign * value);
		temp = value * 10 + (*str - '0');
		if (value != (temp - (*str - '0')) / 10)
			if (sign == 1)
				return (-1);
			else
				return (0);
		else
			value = temp;
		str++;
	}
	return (sign * value);
}

int			ft_atoi(const char *str)
{
	int		sign;

	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+' && sign != -1)
	{
		sign = 1;
		str++;
	}
	return (go_atoi(str, sign));
}
