#include "ft_printf.h"

void    ft_printf_conv_handler(t_settings *settings, t_flags *flags, char conv)
{
    int     i;
    int     total_len;
    char    *str;
    char    car;

    i = -1;
    total_len = 0;
    if (conv == 's')
    {
        str = va_arg(settings->parameters, char*);
        if (str == NULL)
            str = "(null)";
        if (flags->precision_on == 1)
            str = ft_substr(str, 0, flags->precision);
        
        if ((total_len = flags->width - (int)ft_strlen(str)) > 0 && flags->padding_left_minus_sign == 0)//TODO fonction ft_putchar char avec param minus
        {
            while (total_len > 0)
            {
                ft_putchar_fd(flags->pading_character, FD);
                settings->written++;
                total_len--;
            }
        }
        while (str[++i])
        {
            ft_putchar_fd(str[i], FD);
            settings->written++;
        }
        if ((total_len = flags->width - (int)ft_strlen(str)) > 0 && flags->padding_left_minus_sign == 1)//TODO code repetition
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
    if (conv == 'c')
    {
        car = va_arg(settings->parameters, char);
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
        total_len--;
        if (flags->padding_left_minus_sign == 1)
        {
            while ((total_len = flags->width) > 1)
            {
                ft_putchar_fd(flags->pading_character, FD);
                total_len--;
            }
        }
    }

    /*printf("\nINSTANCE PARAMETERS\n");
    printf("\n%d\n", settings->written);
    printf("\nPADDING LEFT : %d\n", flags->padding_left_minus_sign);
    printf("\nWIDTH : %d\n", flags->width);
    printf("\nWIDTH_ON : %d\n", flags->width_on);
    printf("\nPADDING CHAR : %d\n", flags->pading_character);
    printf("\nPRECISION : %d\n", flags->precision);
    printf("\nPRECISION_on : %d\n", flags->precision_on);*/
}