/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <jherelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:41:16 by jherelle          #+#    #+#             */
/*   Updated: 2020/02/11 10:09:25 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_width_s(t_settings *settings, t_flags *flags,
						char **str, int *total_len)
{
	if (flags->precision_on == 1)
		*str = ft_substr(*str, 0, flags->precision);
	if ((*total_len = flags->width - (int)ft_strlen(*str)) > 0
		&& flags->padding_left_minus_sign == 0)
	{
		while (*total_len > 0)
		{
			ft_putchar_fd(flags->pading_character, FD);
			settings->written++;
			*total_len -= 1;
		}
	}
}

void	ft_printf_conv_s(t_settings *settings, t_flags *flags, int *i)
{
	int		total_len;
	char	*str;

	total_len = 0;
	str = va_arg(settings->parameters, char*);
	if (str == NULL)
		str = "(null)";
	ft_printf_width_s(settings, flags, &str, &total_len);
	while (str[(*i) += 1])
	{
		ft_putchar_fd(str[*i], FD);
		settings->written++;
	}
	if ((total_len = flags->width - (int)ft_strlen(str)) > 0 &&
		flags->padding_left_minus_sign == 1)
	{
		while (total_len > 0)
		{
			ft_putchar_fd(flags->pading_character, FD);
			settings->written++;
			total_len--;
		}
	}
	if (flags->precision_on == 1)
		free(str);
}
