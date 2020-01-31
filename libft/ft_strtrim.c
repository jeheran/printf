/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <jherelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:15:24 by jherelle          #+#    #+#             */
/*   Updated: 2020/01/31 14:41:10 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in(int x, char *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (x == set[j])
			return (1);
		j++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		trim_from;
	int		trim_end;
	int		len;

	if (!set || !s1)
		return (NULL);
	i = ft_strlen(s1) - 1;
	len = 0;
	trim_from = 0;
	trim_end = 0;
	while (s1[trim_from] && ft_is_in((char)s1[trim_from], (char *)set))
		trim_from++;
	if (trim_from == i + 1)
		return (ft_strdup(""));
	while (ft_is_in((char)s1[i], (char *)set) && i >= 0)
	{
		trim_end++;
		i--;
	}
	len = (ft_strlen(s1) - trim_end - trim_from);
	if (len < 0)
		len = 0;
	return (ft_substr(s1, trim_from, (len)));
}
