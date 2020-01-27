/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:20:15 by jherelle          #+#    #+#             */
/*   Updated: 2019/11/12 12:39:34 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (dst)
		n = ft_strlen(dst);
	if (n >= dstsize)
		return (dstsize + ft_strlen(src));
	while (i < (dstsize - n - 1) && src[i])
	{
		dst[n + i] = src[i];
		i++;
	}
	dst[n + i] = '\0';
	return (n + ft_strlen(src));
}
