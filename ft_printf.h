#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define FORMAT_TYPES "cspdiuxX"
# define FD 1

/*
** ___________ STRUCTURES __________
*/
typedef struct		s_settings 
{
	int				written;
	const char		*format;
	va_list			parameters;

} 					t_settings;

typedef struct 		s_flags
{
	int				padding_left_minus_sign;
	int				width_on;
	int				width;
	char			pading_character;
	int				precision_on;
	int				precision;

}					t_flags;

/*
** ___________ FUNCTION __________
*/

int    				ft_handle_flags(t_settings *settings, int i);

#endif
