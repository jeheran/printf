/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress_base_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <jherelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:40:02 by jherelle          #+#    #+#             */
/*   Updated: 2020/02/06 16:14:26 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putadress_base_fd(unsigned long adress, char *base, int fd)
{
	unsigned long radix;
	radix = (unsigned long)ft_strlen(base);
	if (adress >= radix)
		ft_putadress_base_fd(adress / radix, base, fd);
	ft_putchar_fd(base[adress % radix], fd);
}