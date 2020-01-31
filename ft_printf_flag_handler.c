/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <jherelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:50:06 by jherelle          #+#    #+#             */
/*   Updated: 2020/01/31 19:02:08 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_set_flags(t_flags *flags)
{
    flags->padding_left_minus_sign = 0;
	flags->width_on = 0;
	flags->width = 0;
	flags->pading_character = ' ';
	flags->precision_on = 0;
	flags->precision = 0;
}    

int ft_handle_flags(t_settings *settings, int i)
{
    t_flags flags;
    int     start;
 
    start = 0;
    ft_set_flags(&flags);
    while(ft_strchr(FORMAT_TYPES, settings->format[i]) == NULL)
    {
        printf("####### NEW INSTANCE ########\n");
        //TODO re-organise in controller
        if (settings->format[i] == '-')
        {
            flags.padding_left_minus_sign = 1;
            i++;
        }
        if (settings->format[i] == '0')
        {
            if (settings->format[i-1] != '-')
                flags.pading_character = '0';
            i++;
        }
        
        // WIDTH
        if (settings->format[i] != '.')
            flags.width_on = 1;
        if (settings->format[i] == '*')
        {
            flags.width = va_arg(settings->parameters, int);
            i++;
        }
        if (settings->format[i] >= '0' && settings->format[i] <= '9')
        {
            start = i;
            while (settings->format[i] >= '0' && settings->format[i] <= '9')
                i++;
            flags.width = ft_atoi(ft_substr(settings->format, start, (i - start)));
            flags.width_on = 1;
        }

        // PRECISION
        if (settings->format[i] == '.')
        {
            flags.precision_on = 1;
            i++;
        }
        if (settings->format[i] == '*')
        {
            flags.precision = va_arg(settings->parameters, int);
            i++;
        }
        if (settings->format[i] >= '0' && settings->format[i] <= '9')
        {
            start = i;
            while (settings->format[i] >= '0' && settings->format[i] <= '9')
                i++;
            flags.precision = ft_atoi(ft_substr(settings->format, start, (i - start)));
        }
    }

    // Deal with conversion
    //printf("\nCONV ==> %c\n", settings->format[i]);
    printf("%c", settings->format[i]);
    ft_printf_conv_handler(settings, &flags, settings->format[i]);
    i++;

    return (i);
}