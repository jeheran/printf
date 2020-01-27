/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:21:23 by jherelle          #+#    #+#             */
/*   Updated: 2019/11/11 09:38:49 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	last_index;

	last_index = ft_lstsize(lst);
	while (last_index > 1)
	{
		lst = lst->next;
		last_index--;
	}
	return (lst);
}
