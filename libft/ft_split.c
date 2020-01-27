/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:43:02 by jherelle          #+#    #+#             */
/*   Updated: 2019/11/12 16:48:49 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int		ft_word_count(char const *str, char c)
{
	int	i;
	int	k;
	int	count;

	i = 0;
	k = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			k = 0;
		if (str[i] != c && ++k == 1)
		{
			k = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int		letters_count(char const *str, char c, int i)
{
	int	count;

	count = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

static char		*ft_create_fill(char const *str, char c, int i)
{
	char	*n_str;
	int		j;

	j = 0;
	if (!(n_str = malloc(sizeof(char*) * (letters_count(str, i, c) + 1))))
		return (0);
	while (str[i] && str[i] != c)
	{
		n_str[j] = str[i];
		j++;
		i++;
	}
	n_str[j] = '\0';
	return (n_str);
}

char			**ft_split(char	const *s, char c)
{
	char	**s_tab;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s || !c)
		return (NULL);
	if (!(s_tab = malloc(sizeof(char*) * (ft_word_count(s, c) + 1))))
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			s_tab[k] = ft_create_fill(s, c, i);
			k++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	s_tab[k] = 0;
	return (s_tab);
}
