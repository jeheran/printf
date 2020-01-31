#include "ft_printf.h"

void    ft_printf_conv_handler(t_settings *settings, t_flags *flags, char conv)
{
    printf("YOOOO");
    printf("%c", conv);
    if (conv == 's')
    {
        printf("CONV %c", conv);
        printf("ARG TO BE PRINTED %s", va_arg(settings->parameters, char*));
    }

    if (conv == 'd')
    {
        printf("CONV %c", conv);
        printf("ARG TO BE PRINTED %d", va_arg(settings->parameters, int));
    }

    printf("\nPADDING LEFT : %d\n", flags->padding_left_minus_sign);
    printf("\nWIDTH : %d\n", flags->width);
    printf("\nWIDTH_ON : %d\n", flags->width_on);
    printf("\nPADDING CHAR : %d\n", flags->pading_character);
    printf("\nPRECISION : %d\n", flags->precision);
    printf("\nPRECISION_on : %d\n", flags->precision_on);
}