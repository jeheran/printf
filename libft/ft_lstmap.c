/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:25:56 by jherelle          #+#    #+#             */
/*   Updated: 2019/11/13 14:46:11 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*next;
	t_list	*tmp;

	if (!lst || !(*f))
		return (0);
	if (!(new_lst = ft_lstnew((*f)(lst->content))))
		return (0);
	tmp = new_lst;
	lst = lst->next;
	while (lst)
	{
		if (!(next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&lst, (*del));
			return (0);
		}
		tmp->next = next;
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new_lst);
}
