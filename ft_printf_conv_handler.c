#include "ft_printf.h"

void    ft_printf_conv_handler(t_settings *settings, t_flags *flags, char conv)
{
    int     i;
    int     j;
    int     total_len;
    char    *str;

    i = 0;
    j = 0;
    total_len = 0;
    if (conv == 's')
    {
        if (flags->precision_on == 1)
            str = ft_substr(va_arg(settings->parameters, char*), 0, flags->precision);
        else
           str = va_arg(settings->parameters, char*);
        
        if ((total_len = flags->width - (int)ft_strlen(str)) > 0 && flags->padding_left_minus_sign == 0)
        {
            while (total_len > 0)
            {
                ft_putchar_fd(flags->pading_character, FD);
                total_len--;
            }
        }
        ft_putstr_fd(str, FD);
        if ((total_len = flags->width - (int)ft_strlen(str)) > 0 && flags->padding_left_minus_sign == 1)
        {
            while (total_len > 0)
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