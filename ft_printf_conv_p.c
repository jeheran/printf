/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <jherelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:56:59 by jherelle          #+#    #+#             */
/*   Updated: 2020/02/11 10:12:35 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_conv_p(t_settings *settings, t_flags *flags, int *i)
{
	int		*len;
	void	*ptr;

	len = 0;
	ptr = va_arg(settings->parameters, void*);
	if (!(ptr == NULL && flags->precision == 0 && flags->precision_on == 1))
		ft_nbr_len_base(ptr, "0123456789abcdef", &len);
	ft_printf_width_ints(settings, flags, len, 0);
	*i = -1;
	ft_putstr_fd("0x", FD);
	settings->written += 2;
	if (flags->precision_on == 1 && flags->precision)
	{
		while (((*i) += 1) < (flags->precision - (int)len))
		{
			ft_putchar_fd('0', FD);
			settings->written += 1;
		}
	}
	if (len != 0)
		ft_putadress_base_fd((unsigned long)ptr, "0123456789abcdef", FD);
	ft_printf_width_neg_ints(settings, flags, len, 0);
}
