/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:03:27 by jherelle          #+#    #+#             */
/*   Updated: 2019/11/12 16:47:36 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' ||
			c == '\n' || c == '\r' || c == '\f');
}

int			ft_atoi(const char *str)
{
	int i;
	int res;
	int neg;

	i = 0;
	res = 0;
	neg = 1;
	while (ft_is_space(str[i]) == 1 && str[i])
		i++;
	if ((str[i] == '+' || str[i] == '-') && str[i])
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1 && str[i])
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * neg);
}
