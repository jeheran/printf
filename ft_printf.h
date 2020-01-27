#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define TYPES = "cspdiuxX"
# define FD = out

typedef struct	s_settings 
{
	int	written;
	int	fd;
	char	*format;
	va_list	parameters;
	int	end;

} 		t_settings;

#endif
