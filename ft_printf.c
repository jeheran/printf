#include "ft_printf.h"



int    ft_printf_handler(t_settings *settings)
{
	int	i;
	
	i = 0;
	while (settings->format[i] != '\0')
	{
		if (settings->format[i] != '%')
		{
			ft_putchar_fd(settings->format[i], FD);
			settings->written++;
			i++;
		}
		else if (settings->format[i] == '%')
		{
			i++;
            i = ft_handle_flags(settings, i);
		}
	}
	return (1);
}

int    ft_printf(const char *format, ...)
{
    t_settings    settings;
    
    settings.written = 0;
    settings.format = format;

    va_start(settings.parameters, format);

    ft_printf_handler(&settings);

    va_end(settings.parameters);

    return (settings.written);
}