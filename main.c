/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 11:41:25 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/13 16:07:05 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	//int		a = 9;
	//int c = 21474836479;

	//ft_printf("number: %0+8d\n", 9);
	//int c = 0xc2a7;
	//printf("%d %d\n", 5);
	//int p = ft_printf("%% %c %0+7.4c");
	char k = 200;
	ft_printf("%s %c %p other\n", "abc", 'k', &k);
	printf("%p\n", &k);
	// if (-1)
	// 	printf("yes\n");
}