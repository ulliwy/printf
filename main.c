/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 11:41:25 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/16 17:10:32 by iprokofy         ###   ########.fr       */
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
	//wchar_t k[] = L"µ©";
	//char *l = "dddd©";
	char i[] = "";

	//ft_printf("wide string: %-*ls\n", 7, k);
	
	//ft_printf("string1: %8.6s\n", l);
	//printf("string2: %8.6s\n", l);

	printf("ptr1: %-20p\n", i);	
	ft_printf("ptr2: %-20.2p\n", i);

}