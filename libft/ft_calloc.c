/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:57:22 by jherelle          #+#    #+#             */
/*   Updated: 2019/11/12 12:26:00 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem_space;

	if (!(mem_space = malloc(size * count)))
		return (NULL);
	ft_memset(mem_space, 0, count * size);
	return (mem_space);
}
