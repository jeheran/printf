#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	// Creation structure d'acceuil
	
	// Assigner format et fd

	// va_start dans structure d'acceuil

	// printf handle

	// va_end

	// Return written
	printf("Format : %s", format);
	printf("\nLEN : %zu", ft_strlen(format));
	return (0);
}

int main()
{
	char	s[] = "ich bin meine maschine";
	ft_printf("%s ich bin meine mashine", s);

}
