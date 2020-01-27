/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:13:10 by jherelle          #+#    #+#             */
/*   Updated: 2019/11/11 09:40:13 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned const char *)s1)[i] == ((unsigned const char *)s2)[i])
			i++;
		else
			return (((unsigned const char *)s1)[i]
							- ((unsigned const char *)s2)[i]);
	}
	return (0);
}
