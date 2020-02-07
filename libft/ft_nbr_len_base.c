/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_len_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <jherelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:10:30 by jherelle          #+#    #+#             */
/*   Updated: 2020/02/07 11:41:57 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nbr_len_base(unsigned long nbr, char* base, int *len)
{
	unsigned long radix;
	*len += 1;
	radix = (unsigned long)ft_strlen(base);
	if (nbr >= radix)
		ft_nbr_len_base(nbr / radix, base, len);
}