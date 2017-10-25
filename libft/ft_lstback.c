/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstback.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:45:13 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/25 15:45:15 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstback(t_list **alst, t_list *new)
{
	t_list	*node;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	node = *alst;
	while (node->next)
		node = node->next;
	node->next = new;
}
