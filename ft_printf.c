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

void	ft_printf_tester()
{
    char	s[] = "modern";
	//char	c = 'Y';
	char	vide[] = "";

	printf("________TESTING_WIDTH_STRING_______\n");
	fflush(stdout);

	ft_printf("ft_printf: test%5s\n", s);
	fflush(stdout);

	printf("==>PRINTF: test%5s\n\n", s);
	fflush(stdout);

	ft_printf("ft_printf: test%*s\n", 2, s);
	fflush(stdout);

	printf("==>PRINTF: test%*s\n\n", 2, s);
	fflush(stdout);

	ft_printf("ft_printf: test%s\n", vide);
	fflush(stdout);

	printf("==>PRINTF: test%s\n\n", vide);
	fflush(stdout);

	ft_printf("ft_printf: test%s\n", s);
	fflush(stdout);

	printf("==>PRINTF: test%s\n\n", s);
	fflush(stdout);

	ft_printf("ft_printf: test%s\n", vide);
	fflush(stdout);

	printf("==>PRINTF: test%s\n\n", vide);
	fflush(stdout);

	ft_printf("ft_printf: test%5s\n", vide); //test6
	fflush(stdout);

	printf("==>PRINTF: test%5s\n\n", vide); //test6
	fflush(stdout);

	ft_printf("ft_printf: test%5s\n", vide);
	fflush(stdout);

	printf("==>PRINTF: test%5s\n\n", vide);
	fflush(stdout);

	ft_printf("ft_printf: test%*s\n", 0, vide);
	fflush(stdout);

	printf("==>PRINTF: test%*s\n\n", 0, vide);
	fflush(stdout);

	ft_printf("ft_printf: test%*s\n", 0, s);
	fflush(stdout);

	printf("==>PRINTF: test%*s\n\n", 0, s);
	fflush(stdout);

	ft_printf("ft_printf: test%*s\n", -4, s);
	fflush(stdout);

	printf("==>PRINTF: test%*s\n\n", -4, s);
	fflush(stdout);

	ft_printf("ft_printf: test%10s\n", s);
	fflush(stdout);

	printf("==>PRINTF: test%10s\n\n", s);
	fflush(stdout);

	ft_printf("ft_printf: test%-10s\n", s);
	fflush(stdout);

	printf("==>PRINTF: test%-10s\n\n", s);
	fflush(stdout);

	ft_printf("ft_printf: test%-10s\n", vide);
	fflush(stdout);

	printf("==>PRINTF: test%-10s\n\n", vide);
	fflush(stdout);

	ft_printf("ft_printf: test%-2s\n", s);
	fflush(stdout);

	printf("==>PRINTF: test%-2s\n\n", s);
	fflush(stdout);


	printf("________TESTING_PRECISION_STRING_______\n");
	//ft_printf("ft_printf: test%.5s\n", s);
	printf("LIB: test%.5s\n", s);
	//ft_printf("ft_printf: test%.*s\n", 2, s);
	printf("LIB: test%.*s\n", 2, s);
	//ft_printf("ft_printf: test%.s\n", vide);
	printf("LIB: test%.s\n", vide);
	//ft_printf("ft_printf: test%.s\n", s);
	printf("LIB: test%.s\n", s);
	//ft_printf("ft_printf: test%.s\n", vide);
	printf("LIB: test%.s\n", vide);
	//ft_printf("ft_printf: test%.5s\n", vide);
	printf("LIB: test%.5s\n", vide);
	//ft_printf("ft_printf: test%.5s\n", vide);
	printf("LIB: test%.5s\n", vide);
	//ft_printf("ft_printf: test%.*s\n", 0, vide);
	printf("LIB: test%.*s\n", 0, vide);
	//ft_printf("ft_printf: test%.*s\n", 0, s);
	printf("LIB: test%.*s\n", 0, s);
	//ft_printf("ft_printf: test%.*s\n", -2, s);
	printf("LIB: test%.*s\n", -2, s);
	//ft_printf("ft_printf: test%.10s\n", s);
	printf("LIB: test%.10s\n", s);

	printf("________TESTING_COMBO_PRECISION_X_WIDTH_STRING_______\n");
	fflush(stdout);

	ft_printf("ft_printf: test%-2.5s\n", s);
	fflush(stdout);

	printf("==>PRINTF: test%-2.5s\n", s);
	fflush(stdout);

	ft_printf("ft_printf: test%10.*s\n", 2, s);
	fflush(stdout);

	printf("==>PRINTF: test%10.*s\n", 2, s);
	fflush(stdout);

	ft_printf("ft_printf: test%5.10s\n", vide);
	fflush(stdout);

	printf("==>PRINTF: test%5.10s\n", vide);
	fflush(stdout);

	//ft_printf("ft_printf: test%10.5s\n", s);
	printf("==>PRINTF: test%10.5s\n", s);
	//ft_printf("ft_printf: test%10.5s\n", vide);
	printf("==>PRINTF: test%10.5s\n", vide);
	//ft_printf("ft_printf: test%2.5s\n", vide);
	printf("==>PRINTF: test%2.5s\n", vide);
	//ft_printf("ft_printf: test%20.5s\n", vide);
	printf("==>PRINTF: test%20.5s\n", vide);
	//ft_printf("ft_printf: test%-1.*s\n", 0, vide);
	printf("==>PRINTF: test%-1.*s\n", 0, vide);
	//ft_printf("ft_printf: test%*.*s\n",10, 0, s);
	printf("==>PRINTF: test%*.*s\n",10, 0, s);
	//ft_printf("ft_printf: test%*.*s\n",-5, -2, s);
	printf("==>PRINTF: test%*.*s\n",-5, -2, s);
	//ft_printf("ft_printf: test%-10.10s\n", s);
	printf("==>PRINTF: test%-10.10s\n", s);

	/*printf("________TESTING_WIDTH_CHAR_______\n");
	ft_printf("ft_printf: test%5c\n", c);
	printf("LIB: test%5c\n", c);
	ft_printf("ft_printf: test%*c\n", 2, c);
	printf("LIB: test%*c\n", 2, c);
	ft_printf("ft_printf: test%c\n", c);
	printf("LIB: test%c\n", c);
	ft_printf("ft_printf: test%*c\n", 0, c);
	printf("LIB: test%*c\n", 0, c);
	ft_printf("ft_printf: test%*c\n", -2, c);
	printf("LIB: test%*c\n", -2, c);
	ft_printf("ft_printf: test%10c\n", c);
	printf("LIB: test%10c\n", c);
	ft_printf("ft_printf: test%-10c\n", c);
	printf("LIB: test%-10c\n", c);
	ft_printf("ft_printf: test%-2c\n", c);
	printf("LIB: test%-2c\n", c);*/


	printf("________TESTING_WIDTH_INT_______\n");
}

int main()
{
    //int    i = 20;
    printf("\n====================RESULT==================\n");
    //ft_printf("ich bin meine %5.2s maschine n°%d.\n", i);
	ft_printf_tester();
}
