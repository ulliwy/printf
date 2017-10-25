/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:16:31 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/21 17:16:33 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*fresh_start;
	t_list	*prev;

	if (lst)
	{
		fresh = ft_lstnew(lst->content, lst->content_size);
		fresh = f(fresh);
		if (fresh)
			fresh_start = fresh;
		else
			return (NULL);
		prev = fresh;
		lst = lst->next;
	}
	while (lst)
	{
		fresh = ft_lstnew(lst->content, lst->content_size);
		fresh = f(fresh);
		prev->next = fresh;
		prev = prev->next;
		lst = lst->next;
	}
	return (fresh_start);
}
