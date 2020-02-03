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
    str = va_arg(settings->parameters, char*);
    if (conv == 's')
    {
        //affectation de la len totale
        if (flags->width > (int)ft_strlen(str))
            total_len = flags->width;
        else
            total_len = (int)ft_strlen(str);
        if (flags->precision_on == 1 && flags->precision < flags->width)
            total_len = flags->width;
        else if (flags->precision_on == 1 && flags->precision >= flags->width)
            total_len = flags->precision;

        //si pas de moins
        if (flags->padding_left_minus_sign == 0)
        {
            if (flags->precision_on == 1 && flags->precision < flags->width)
            {
                while(total_len > flags->precision)
                {
                    ft_putchar_fd(flags->pading_character, FD);
                    total_len--;
                }
            }
            else
            {
                while(total_len > (int)ft_strlen(str))
                {
                    ft_putchar_fd(flags->pading_character, FD);
                    total_len--;
                }
            }
        }

        //ecrire str en entier
        while (str[i] && total_len > 0)
        {
            ft_putchar_fd(str[i], FD);
            i++;
            total_len--;
        }
        
        //si '-'
        if (flags->padding_left_minus_sign == 1)
        {
            if ((int)ft_strlen(str) < flags->precision)
            {
                total_len = flags->precision;
                while (total_len > 0)
                {
                    ft_putchar_fd(flags->pading_character, FD);
                    total_len--;
                }
            }
            else
            {
                while (total_len > 0)
                {
                    ft_putchar_fd(flags->pading_character, FD);
                    total_len--;
                }
            }
        }

        //si pas de width

        //si combo
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