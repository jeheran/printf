/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <jherelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:34:22 by jherelle          #+#    #+#             */
/*   Updated: 2020/02/11 10:49:36 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_conv_x(t_settings *settings, t_flags *flags,
							int *i, char conv)
{
	int				*len;
	unsigned int	ptr;

	len = 0;
	ptr = va_arg(settings->parameters, unsigned int);
	if (!(ptr == NULL && flags->precision == 0 && flags->precision_on == 1))
		ft_nbr_len_base(ptr, "0123456789abcdef", &len);
	ft_printf_width_ints(settings, flags, len, 0);
	*i = -1;
	if (flags->precision_on == 1 && flags->precision)
	{
		while (((*i) += 1) < (flags->precision - (int)len))
		{
			ft_putchar_fd('0', FD);
			settings->written += 1;
		}
	}
	if (len != 0)
		ft_putadress_base_fd((unsigned long)ptr, conv == 'x' ?
							"0123456789abcdef" : "0123456789ABCDEF", FD);
	ft_printf_width_neg_ints(settings, flags, len, 0);
}
