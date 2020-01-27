/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:18:45 by jherelle          #+#    #+#             */
/*   Updated: 2019/11/11 09:39:38 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst2;
	unsigned const char	*src2;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dst2 = dst;
	src2 = src;
	if (n != 0)
		while (i < n)
		{
			dst2[i] = src2[i];
			i++;
		}
	return (dst);
}
