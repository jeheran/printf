/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:32:48 by jherelle          #+#    #+#             */
/*   Updated: 2019/11/06 10:57:57 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	if ((char)c == '\0')
		return ((char *)s + ft_strlen((char *)s));
	while (((char *)s)[i])
	{
		if ((char)c == ((char *)s)[i])
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
