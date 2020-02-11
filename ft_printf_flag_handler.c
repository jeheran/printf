/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <jherelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:50:06 by jherelle          #+#    #+#             */
/*   Updated: 2020/02/11 11:01:01 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_width(t_settings *settings, t_flags *flags, int *i)
{
	int start;

	start = 0;
	flags->width_on = 1;
	if (settings->format[*i] >= '0' && settings->format[*i] <= '9')
	{
		start = *i;
		while (settings->format[*i] >= '0' && settings->format[*i] <= '9')
			*i += 1;
		flags->width = ft_atoi(settings->format + start);
	}
	if (settings->format[*i] == '*')
	{
		flags->width = va_arg(settings->parameters, int);
		*i += 1;
	}
}

void	ft_flag_precision(t_settings *settings, t_flags *flags, int *i)
{
	int start;
	int numbered;

	start = 0;
	numbered = 0;
	flags->precision_on = 1;
	*i += 1;
	if (settings->format[*i] >= '0' && settings->format[*i] <= '9')
	{
		start = *i;
		while (settings->format[*i] >= '0' && settings->format[*i] <= '9')
			*i += 1;
		flags->precision = ft_atoi(settings->format + start);
		numbered = 1;
	}
	if (settings->format[*i] == '*' && (*i += 1))
	{
		if (numbered && flags->precision == 0)
		{
			flags->width = va_arg(settings->parameters, int);
			flags->width_on = 1;
		}
		else
			flags->precision = va_arg(settings->parameters, int);
	}
}

void	ft_handle_negative_flags(t_flags *flags)
{
	if (flags->width < 0)
	{
		flags->padding_left_minus_sign = 1;
		flags->width = ft_abs_value(flags->width);
		flags->pading_character = ' ';
	}
	if (flags->precision < 0)
	{
		flags->precision_on = 0;
		flags->precision = 0;
		flags->precision_neg = 1;
	}
}

void	ft_handle_flags_utils(t_settings *settings, t_flags *flags, int *i)
{
	if (settings->format[*i] == '-' && ((*i) += 1))
	{
		flags->padding_left_minus_sign = 1;
		return ;
	}
	if (settings->format[*i] == '0' && ((*i) += 1))
	{
		flags->pading_character = settings->format[*i - 2] != '-' ? '0' : ' ';
		return ;
	}
	if (settings->format[*i] != '.')
		ft_flag_width(settings, flags, i);
	ft_handle_negative_flags(flags);
	if (settings->format[*i] == '.')
		ft_flag_precision(settings, flags, i);
	ft_handle_negative_flags(flags);
}

int		ft_handle_flags(t_settings *settings, int i)
{
	t_flags flags;

	ft_memset(&flags, 0, sizeof(t_flags));
	flags.pading_character = ' ';
	while (ft_strchr(FLAGS_CHARS, settings->format[i]) != NULL
		&& ft_strchr(FORMAT_TYPES, settings->format[i]) == NULL)
		ft_handle_flags_utils(settings, &flags, &i);
	flags.conv = settings->format[i];
	ft_printf_conv_handler(settings, &flags, settings->format[i]);
	return (i + 1);
}
