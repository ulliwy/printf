/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:49:39 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/21 16:49:41 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*current;

	if (!*alst)
		return ;
	current = *alst;
	while (current)
	{
		temp = current;
		current = current->next;
		ft_lstdelone(&temp, del);
	}
	*alst = NULL;
}
