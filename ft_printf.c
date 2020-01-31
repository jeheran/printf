#include "ft_printf.h"

void    ft_printf_handler(t_settings *settings)
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
            ft_printf_flag_handler(settings, i);
		}
	}
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

int main()
{
    char   s[] = "modern";
    //int    i = 2;
    printf("\n====================RESULT==================\n");
    ft_printf("ich bin meine %s mashine n°%d\n", s, 444);
    //printf("test %0*i", 100, i);
}
