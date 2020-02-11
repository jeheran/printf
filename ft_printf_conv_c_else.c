/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_c_else.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <jherelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:05:40 by jherelle          #+#    #+#             */
/*   Updated: 2020/02/11 09:51:54 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void
	ft_printf_conv_c_else(t_settings *settings, t_flags *flags,
							char car, int *i)
{
	int total_len;

	total_len = 1;
	if (flags->width_on == 1 && flags->width > 1)
		total_len = flags->width;
	settings->written += total_len;
	if (flags->padding_left_minus_sign == 0)
	{
		while (total_len > 1)
		{
			ft_putchar_fd(flags->pading_character, FD);
			total_len--;
		}
	}
	ft_putchar_fd(car, FD);
	if (flags->padding_left_minus_sign == 1)
	{
		while (total_len > 1)
		{
			ft_putchar_fd(flags->pading_character, FD);
			total_len--;
		}
	}
}
