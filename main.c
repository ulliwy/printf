/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 11:41:25 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/17 17:37:47 by iprokofy         ###   ########.fr       */
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
	//char i[] = "0x7fff5768af";
	//int len;
	int n1 = 0;
	int n2 = 889;

	//ft_printf("wide string: %-*ls\n", 7, k);
	
	//ft_printf("string1: %8.6s\n", l);
	//printf("string2: %8.6s\n", l);

	//printf("ptr1: %20p\n", i);	
	//len = ft_printf("ptr2: %20p\n", i);
	//printf("%d\n", len);

	printf("%d: \n", printf("%.0d\n", n1));
	printf("%d: \n", ft_printf("%.0d\n", n1));

	printf("%d: \n", printf("nbr1: \"%.0d\"\n", n1));
	printf("%d: \n", ft_printf("nbr2: \"%.0d\"\n", n1));

	printf("%d: \n", printf("nbr1: \"%d\"\n", n1));
	printf("%d: \n", ft_printf("nbr2: \"%d\"\n", n1));

	printf("%d: \n", printf("nbr1: \"%4.0d\"\n", n1));
	printf("%d: \n", ft_printf("nbr2: \"%4.0d\"\n", n1));

	printf("%d: \n", printf("nbr1: \"%+8.4d\"\n", n2));
	printf("%d: \n", ft_printf("nbr2: \"%+08.4d\"\n", n2));

	printf("%d: \n", printf("nbr1: \"%+08d\"\n", n2));
	printf("%d: \n", ft_printf("nbr2: \"%+08d\"\n", n2));

	printf("%d: \n", printf("nbr1: \"%+8d\"\n", n2));
	printf("%d: \n", ft_printf("nbr2: \"%+8d\"\n", n2));

	printf("%d: \n", printf("nbr1: \"%-+8.4d\"\n", n2));
	printf("%d: \n", ft_printf("nbr2: \"%-+8.4d\"\n", n2));

}