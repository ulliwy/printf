/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:59:11 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/21 16:59:13 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*node;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	node = new;
	node->next = *alst;
	*alst = node;
}
