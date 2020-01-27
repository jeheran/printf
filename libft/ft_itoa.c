/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:16:31 by jherelle          #+#    #+#             */
/*   Updated: 2019/11/12 12:46:46 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_int_len(long int n)
{
	int c;

	c = 1;
	while (n >= 10)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char		*ft_itoa(int n)
{
	char		*str;
	int			neg;
	int			l;
	long int	m;

	neg = 0;
	m = n;
	if (m < 0)
	{
		neg = 1;
		m *= -1;
	}
	l = ft_int_len(m);
	if (!(str = (char*)malloc(sizeof(char) * (l + neg + 1))))
		return (0);
	str[l + neg] = '\0';
	while (l > 0)
	{
		str[l - 1 + neg] = (m % 10) + 48;
		m /= 10;
		l--;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
