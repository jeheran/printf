/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_lstnew_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:27:22 by jherelle          #+#    #+#             */
/*   Updated: 2019/11/11 10:40:10 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*first_el;

	if (!(first_el = malloc(sizeof(t_list))))
		return (0);
	first_el->content = content;
	first_el->next = NULL;
	return (first_el);
}
