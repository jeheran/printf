/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <jherelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:42:30 by jherelle          #+#    #+#             */
/*   Updated: 2020/02/11 10:48:49 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_conv_handler(t_settings *settings, t_flags *flags, char conv)
{
	int		i;

	i = -1;
	if (conv == 's')
		ft_printf_conv_s(settings, flags, &i);
	else if (conv == 'p')
		ft_printf_conv_p(settings, flags, &i);
	else if (conv == 'x' || conv == 'X')
		ft_printf_conv_x(settings, flags, &i, conv);
	else if (conv == 'u')
		ft_printf_conv_u(settings, flags, &i);
	else if (conv == 'd' || conv == 'i')
		ft_printf_conv_d_i(settings, flags, &i);
	else
	{
		if (conv == 'c')
			conv = va_arg(settings->parameters, char);
		ft_printf_conv_c_else(settings, flags, conv, &i);
	}
}
