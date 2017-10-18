/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 11:41:25 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/18 13:50:20 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	// int n1 = 0;
	// int n2 = 889;

	// printf(" \"%d\" \n", printf("@moulitest: %#.0o", 0));
	// printf(" \"%d\" \n", ft_printf("@moulitest: %#.0o", 0));

	// printf(" \"%d\" \n", printf("%.10d", 4242));
	// printf(" \"%d\" \n", ft_printf("%.10d", 4242));

	printf(" \"%d\" \n", printf("@moulitest: %s", NULL));
	printf(" \"%d\" \n", ft_printf("@moulitest: %s", NULL));

	// printf(" \"%d\" \n", printf("%#-8x", 42));
	// printf(" \"%d\" \n", ft_printf("%#-08x", 42));

	// printf("%d: \n", printf("nbr1: \"%.0d\"\n", n1));
	// printf("%d: \n", ft_printf("nbr2: \"%.0d\"\n", n1));

	// printf("%d: \n", printf("nbr1: \"%d\"\n", n1));
	// printf("%d: \n", ft_printf("nbr2: \"%d\"\n", n1));

	// printf("%d: \n", printf("nbr1: \"%4.0d\"\n", n1));
	// printf("%d: \n", ft_printf("nbr2: \"%4.0d\"\n", n1));

	// printf("%d: \n", printf("nbr1: \"%+8.4d\"\n", n2));
	// printf("%d: \n", ft_printf("nbr2: \"%+08.4d\"\n", n2));

	// printf("%d: \n", printf("nbr1: \"%+08d\"\n", n2));
	// printf("%d: \n", ft_printf("nbr2: \"%+08d\"\n", n2));

	// printf("%d: \n", printf("nbr1: \"%+8d\"\n", n2));
	// printf("%d: \n", ft_printf("nbr2: \"%+8d\"\n", n2));

	// printf("%d: \n", printf("nbr1: \"%-+8.4d\"\n", n2));
	// printf("%d: \n", ft_printf("nbr2: \"%-+8.4d\"\n", n2));

	// int u1 = 0xabcd;
	// long int u2 = 15;
	// unsigned long u3 = 4294967295;
	// unsigned long u4 = -4294967295;
	// unsigned long long u5 = -1;

	// int k = printf("%#5x\n", 42);
	// printf("ret1 = %d\n", k);
	// k = ft_printf("%#5x\n", 42);
	// printf("ret2 = %d\n", k);

	// printf("1: %d\n", u1);
	// ft_printf("1: %d\n", u1);

	// printf("2: %x\n", u1);
	// ft_printf("2: %x\n", u1);

	// printf("3: %X\n", u1);
	// ft_printf("3: %X\n", u1);

	// printf("4: %010lX\n", u2);
	// ft_printf("4: %010lX\n", u2);

	// printf("5: %lu\n", u3);
	// ft_printf("5: %lu\n", u3);

	// printf("6: %lu\n", u4);
	// ft_printf("6: %lu\n", u4);

	// printf("7: %llu\n", u5);
	// ft_printf("7: %llu\n", u5);

	// printf("7: %lO\n", u4);
	// ft_printf("7: %O\n", u4);
}