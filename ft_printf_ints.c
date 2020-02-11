/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <jherelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:21:11 by jherelle          #+#    #+#             */
/*   Updated: 2020/02/11 10:52:19 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_width_ints(t_settings *settings,
									t_flags *flags, int *len, int neg)
{
	int i;
	int	delta;
	int	max;

	i = -1;
	delta = 0;
	max = 0;
	if (flags->conv == 'p')
		delta = 2;
	if (flags->width_on == 1 && flags->padding_left_minus_sign == 0
				&& flags->pading_character == '0' && flags->precision_on == 0)
	{
		flags->width_on = 0;
		flags->precision_on = 1;
		flags->precision = ft_max(flags->width - neg - delta, flags->precision);
	}
	if (flags->width_on == 1 && flags->padding_left_minus_sign == 0)
	{
		max = (flags->width - neg - delta - ft_max(flags->precision, len));
		if (flags->precision_neg)
			max = (flags->width - (int)len - neg - delta) + (flags->precision_on
						&& flags->width_on && flags->precision != 0);
		while ((i += 1) < max && (settings->written += 1))
			ft_putchar_fd(' ', FD);
	}
}

void	ft_printf_width_neg_ints(t_settings *settings,
										t_flags *flags, int *len, int neg)
{
	int i;
	int	delta;

	delta = 0;
	if (flags->conv == 'p')
		delta = 2;
	settings->written += (int)len;
	i = -1;
	if (flags->padding_left_minus_sign == 1)
	{
		while ((i += 1) < (flags->width - neg - delta
							- ft_max(flags->precision, (int)len)))
		{
			ft_putchar_fd(' ', FD);
			settings->written += 1;
		}
	}
}
