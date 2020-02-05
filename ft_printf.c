#include "ft_printf.h"

# include <stdarg.h>
# include <stdio.h>

#define X(format, ...) \
	printf("\e[1m\e[7m\e[92m\e[107m--------------------------------\e[0m\n"); \
	printf("\e[95m...\e[0m"); \
	r1 = printf(format, ##__VA_ARGS__); \
	fflush(stdout); \
	printf("\e[95m...\e[0m\n\e[95m...\e[0m"); \
	fflush(stdout); \
	r2 = ft_printf(format, ##__VA_ARGS__); \
	printf("\e[95m...\e[0m\n"); \
	fflush(stdout); \
	if (r1 != r2) \
	{ \
		printf("\e[91mReturn ERROR: \e[32m%d \e[97m!= \e[32m%d\e[0m\n", r1, r2); \
		printf("\e[1m\e[7m\e[91m\e[107m--------------------------------\e[0m\n\n\n"); \
	}

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
	char	vide[] = "yo";

	int r1, r2;
	//X("%s", 0); // TODO
	X("%s", "chapi");
	X("%s", "");
	X("%s", "LoL");
	X("%s", "chaussette");
	X("%s", "Un gros test qui marche!");
	/*X("%3*s", 0, "Un gros test qui marche!");
	X("%3*s", 3, "Un gros test qui marche!");
	X("%3*s", 10, "Un gros test qui marche!");
	X("%3*s", -15, "Un gros test qui marche!");
	X("%10*s", 0, "Un gros test qui marche!");
	X("%10*s", 3, "Un gros test qui marche!");
	X("%10*s", 10, "Un gros test qui marche!");
	X("%10*s", -15, "Un gros test qui marche!");*/
	X("%*.s", 0, "Un gros test qui marche!");
	X("%*.0s", 0, "Un gros test qui marche!");
	X("%*.3s", 0, "Un gros test qui marche!");
	X("%*.10s", 0, "Un gros test qui marche!");
	X("%*.*s", 0, 0, "Un gros test qui marche!");
	X("%*.*s", 0, 3, "Un gros test qui marche!");
	X("%*.*s", 0, 10, "Un gros test qui marche!");
	X("%*.*s", 0, -15, "Un gros test qui marche!");
	X("%*.s", 3, "Un gros test qui marche!");
	X("%*.0s", 3, "Un gros test qui marche!");
	X("%*.3s", 3, "Un gros test qui marche!");
	X("%*.10s", 3, "Un gros test qui marche!");
	X("%*.*s", 3, 0, "Un gros test qui marche!");
	X("%*.*s", 3, 3, "Un gros test qui marche!");
	X("%*.*s", 3, 10, "Un gros test qui marche!");
	X("%*.*s", 3, -15, "Un gros test qui marche!");
	X("%*.s", 10, "Un gros test qui marche!");
	X("%*.0s", 10, "Un gros test qui marche!");
	X("%*.3s", 10, "Un gros test qui marche!");
	X("%*.10s", 10, "Un gros test qui marche!");
	X("%*.*s", 10, 0, "Un gros test qui marche!");
	X("%*.*s", 10, 3, "Un gros test qui marche!");
	X("%*.*s", 10, 10, "Un gros test qui marche!");
	X("%*.*s", 10, -15, "Un gros test qui marche!");
	X("%*.s", -15, "Un gros test qui marche!");
	X("%*.0s", -15, "Un gros test qui marche!");
	X("%*.3s", -15, "Un gros test qui marche!");
	X("%*.10s", -15, "Un gros test qui marche!");
	X("%*.*s", -15, 0, "Un gros test qui marche!");
	X("%*.*s", -15, 3, "Un gros test qui marche!");
	X("%*.*s", -15, 10, "Un gros test qui marche!");
	X("%*.*s", -15, -15, "Un gros test qui marche!");
	/*X("%3*s", 0, "chaussette");
	X("%3*s", 3, "chaussette");
	X("%3*s", 10, "chaussette");
	X("%3*s", -15, "chaussette");
	X("%10*s", 0, "chaussette");
	X("%10*s", 3, "chaussette");
	X("%10*s", 10, "chaussette");
	X("%10*s", -15, "chaussette");*/ //TODO
	X("%*.s", 0, "chaussette");
	X("%*.0s", 0, "chaussette");
	X("%*.3s", 0, "chaussette");
	X("%*.10s", 0, "chaussette");
	X("%*.*s", 0, 0, "chaussette");
	X("%*.*s", 0, 3, "chaussette");
	X("%*.*s", 0, 10, "chaussette");
	X("%*.*s", 0, -15, "chaussette");
	X("%*.s", 3, "chaussette");
	X("%*.0s", 3, "chaussette");
	X("%*.3s", 3, "chaussette");
	X("%*.10s", 3, "chaussette");
	X("%*.*s", 3, 0, "chaussette");
	X("%*.*s", 3, 3, "chaussette");
	X("%*.*s", 3, 10, "chaussette");
	X("%*.*s", 3, -15, "chaussette");
	X("%*.s", 10, "chaussette");
	X("%*.0s", 10, "chaussette");
	X("%*.3s", 10, "chaussette");
	X("%*.10s", 10, "chaussette");
	X("%*.*s", 10, 0, "chaussette");
	X("%*.*s", 10, 3, "chaussette");
	X("%*.*s", 10, 10, "chaussette");
	X("%*.*s", 10, -15, "chaussette");
	X("%*.s", -15, "chaussette");
	X("%*.0s", -15, "chaussette");
	X("%*.3s", -15, "chaussette");
	X("%*.10s", -15, "chaussette");
	X("%*.*s", -15, 0, "chaussette");
	X("%*.*s", -15, 3, "chaussette");
	X("%*.*s", -15, 10, "chaussette");
	X("%*.*s", -15, -15, "chaussette");
	/*X("%03s", "LoL");
	X("%010s", "LoL");
	X("%3*s", 0, "LoL");
	X("%3*s", 3, "LoL");
	X("%3*s", 10, "LoL");
	X("%3*s", -15, "LoL");
	X("%10*s", 0, "LoL");
	X("%10*s", 3, "LoL");
	X("%10*s", 10, "LoL");
	X("%10*s", -15, "LoL");*///TODO
	X("%*.s", 0, "LoL");
	X("%*.0s", 0, "LoL");
	X("%*.3s", 0, "LoL");
	X("%*.10s", 0, "LoL");
	X("%*.*s", 0, 0, "LoL");
	X("%*.*s", 0, 3, "LoL");
	X("%*.*s", 0, 10, "LoL");
	X("%*.*s", 0, -15, "LoL");
	X("%*.s", 3, "LoL");
	X("%*.0s", 3, "LoL");
	X("%*.3s", 3, "LoL");
	X("%*.10s", 3, "LoL");
	X("%*.*s", 3, 0, "LoL");
	X("%*.*s", 3, 3, "LoL");
	X("%*.*s", 3, 10, "LoL");
	X("%*.*s", 3, -15, "LoL");
	X("%*.s", 10, "LoL");
	X("%*.0s", 10, "LoL");
	X("%*.3s", 10, "LoL");
	X("%*.10s", 10, "LoL");
	X("%*.*s", 10, 0, "LoL");
	X("%*.*s", 10, 3, "LoL");
	X("%*.*s", 10, 10, "LoL");
	X("%*.*s", 10, -15, "LoL");
	X("%*.s", -15, "LoL");
	X("%*.0s", -15, "LoL");
	X("%*.3s", -15, "LoL");
	X("%*.10s", -15, "LoL");
	X("%*.*s", -15, 0, "LoL");
	X("%*.*s", -15, 3, "LoL");
	X("%*.*s", -15, 10, "LoL");
	X("%*.*s", -15, -15, "LoL");

	return;
	printf("________TESTING_WIDTH_STRING_______\n");
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%5s\n", s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%5s\n\n", s));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%*s\n", 2, s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%*s\n\n", 2, s));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%s\n\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%s\n", s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%s\n\n", s));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%s\n\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%5s\n", vide)); //test6
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%5s\n\n", vide)); //test6
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%5s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%5s\n\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%*s\n", 0, vide));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%*s\n\n", 0, vide));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%*s\n", 0, s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%*s\n\n", 0, s));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%*s\n", -4, s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%*s\n\n", -4, s));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%10s\n", s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%10s\n\n", s));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%-10s\n", s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%-10s\n\n", s));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%-10s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%-10s\n\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%-2s\n", s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%-2s\n\n", s));
	fflush(stdout);


	printf("________TESTING_PRECISION_STRING_______\n");
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%.5s\n", s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%.5s\n", s));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%.*s\n", 2, s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%.*s\n", 2, s));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%.s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%.s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%.s\n", s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%.s\n", s));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%.s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%.s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%.5s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%.5s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%.5s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%.5s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%.*s\n", 0, vide));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%.*s\n", 0, vide));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%.*s\n", 0, s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%.*s\n", 0, s));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%.*s\n", -2, s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%.*s\n", -2, s));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%.10s\n", s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%.10s\n", s));
	fflush(stdout);


	printf("________TESTING_COMBO_PRECISION_X_WIDTH_STRING_______\n");
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%-2.5s\n", s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%-2.5s\n", s));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%10.*s\n", 2, s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%10.*s\n", 2, s));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%5.10s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%5.10s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%10.5s\n", s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%10.5s\n", s));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%10.5s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%10.5s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%2.5s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%2.5s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%20.5s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%20.5s\n", vide));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%-1.*s\n", 0, vide));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%-1.*s\n", 0, vide));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%*.*s\n",10, 0, s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%*.*s\n",10, 0, s));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%*.*s\n",-5, -2, s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%*.*s\n",-5, -2, s));
	fflush(stdout);

	printf("return ~~~> %d", ft_printf("ft_printf: test%-10.10s\n", s));
	fflush(stdout);

	printf("return ~~~> %d", printf("==>PRINTF: test%-10.10s\n", s));

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

int main2()
{
    //int    i = 20;
    printf("\n====================RESULT==================\n");
    //ft_printf("ich bin meine %5.2s maschine n°%d.\n", i);
	ft_printf_tester();
	return (0);
}
