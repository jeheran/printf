/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_d_i.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <jherelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:56:31 by jherelle          #+#    #+#             */
/*   Updated: 2020/02/11 10:43:27 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_conv_d_i(t_settings *settings, t_flags *flags, int *i)
{
	int		neg;
	long	nbr;
	int		*len;

	len = 0;
	nbr = 0 + va_arg(settings->parameters, int);
	neg = nbr < 0;
	nbr = neg ? -nbr : nbr;
	if (!(nbr == 0 && flags->precision == 0 && flags->precision_on == 1))
		ft_nbr_len_base(nbr, "0123456789", &len);
	ft_printf_width_ints(settings, flags, len, neg);
	if (neg)
		ft_putstr_fd("-", FD);
	settings->written += neg;
	if (flags->precision_on == 1 && flags->precision)
	{
		while (((*i) += 1) < (flags->precision - (int)len))
		{
			ft_putchar_fd('0', FD);
			settings->written += 1;
		}
	}
	if (len != 0)
		ft_putadress_base_fd(nbr, "0123456789", FD);
	ft_printf_width_neg_ints(settings, flags, len, neg);
}
