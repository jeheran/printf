/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <jherelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:50:06 by jherelle          #+#    #+#             */
/*   Updated: 2020/02/05 16:22:02 by jherelle         ###   ########.fr       */
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
    int     zero_skip;
 
    start = 0;
    zero_skip = 0;
    ft_set_flags(&flags);
    while(ft_strchr(FORMAT_TYPES, settings->format[i]) == NULL)
    {
        //printf("\n####### NEW INSTANCE ########\n");
        //TODO re-organise in controller
        if (settings->format[i] == '-')
        {
            flags.padding_left_minus_sign = 1;
            i++;
            continue;
        }

        if (settings->format[i] == '0')
        {
            if (settings->format[i-1] != '-')
                flags.pading_character = '0';
            i++;
            continue;
        }
        
        // WIDTH
        if (settings->format[i] != '.')
        {
            flags.width_on = 1;

            if (settings->format[i] >= '0' && settings->format[i] <= '9')
            {
                start = i;
                while (settings->format[i] >= '0' && settings->format[i] <= '9')
                    i++;
                flags.width = ft_atoi(settings->format + start);
            }
            
            if (settings->format[i] == '*')
            {
                flags.width = va_arg(settings->parameters, int);
                i++;
            }
        }
            
        if (flags.width < 0)
        {
            flags.padding_left_minus_sign = 1;
            flags.width = ft_abs_value(flags.width);
            flags.pading_character = ' ';
        }

        // PRECISION
        if (settings->format[i] == '.')
        {
            flags.precision_on = 1;
            i++;

            int numbered = 0;

            if (settings->format[i] >= '0' && settings->format[i] <= '9')
            {
                start = i;
                while (settings->format[i] >= '0' && settings->format[i] <= '9')
                    i++;
                flags.precision = ft_atoi(settings->format + start);

                numbered = 1;
            }

            if (settings->format[i] == '*')
            {
                if (numbered && flags.precision == 0)
                    flags.width = va_arg(settings->parameters, int);
                else
                    flags.precision = va_arg(settings->parameters, int);
                i++;
            }
        }
            
        if (flags.width < 0)
        {
            flags.padding_left_minus_sign = 1;
            flags.width = ft_abs_value(flags.width);
            flags.pading_character = ' ';
        }
            
        if (flags.precision < 0)
        {
            flags.precision_on = 0;
            flags.precision = ft_abs_value(flags.precision);
        }

        /*if (settings->format[i] == '*')
        {
            flags.precision = va_arg(settings->parameters, int);
            i++;
        }
        //while (settings->format[i + zero_skip] == '0' && settings->format[i + zero_skip])
        //    zero_skip++;
        if (settings->format[i] >= '0' && settings->format[i] <= '9')
        {
            start = i;
            while (settings->format[i] >= '0' && settings->format[i] <= '9')
                i++;
            flags.precision = ft_atoi(ft_substr(settings->format, start, (i - start)));
        }
        else if (settings->format[i] == '*')
        {
            flags.precision_on = 1;
            flags.precision = va_arg(settings->parameters, int);
            i++;
        }

        if (settings->format[i] == '*')
        {
            flags.width_on = 1;
            flags.width = va_arg(settings->parameters, int);
            i++;
        }

        if (flags.precision < 0)
            flags.padding_left_minus_sign = 1;

        /*if (zero_skip != 0)
        {
            flags.width_on = 1;
            flags.width = ft_abs_value(flags.precision);
            flags.pading_character = ' ';
            flags.precision = 0;
            flags.precision_on = 1;
        }*/
        //printf("precision ~~> %d ", flags.precision);
        //printf("width ~~> %d", flags.width);
        //printf("char ~~> %d", flags.pading_character);

    }

    // Deal with conversion
    //printf("\nCONV ====> %c\n", settings->format[i]);
    ft_printf_conv_handler(settings, &flags, settings->format[i]);
    i++;

    return (i);
}