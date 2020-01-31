#include "ft_printf.h"

void    ft_handle_flags(t_settings *settings, int i)
{
    printf("%s", settings->format[i]);
}