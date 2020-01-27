/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:29:26 by jherelle          #+#    #+#             */
/*   Updated: 2019/11/11 09:36:39 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (new == NULL)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		last = ft_lstlast(*alst);
		if (last != NULL)
			last->next = new;
	}
}
