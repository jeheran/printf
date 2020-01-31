#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include "ft_printf_flag_handler.c"
# include <stdarg.h>
# include <stdio.h>

# define FORMAT_TYPES "cspdiuxX"
# define FD 1

/*
** ___________ STRUCTURES __________
*/
typedef struct		s_settings 
{
	int			written;
	const char	*format;
	va_list		parameters;

} 					t_settings;

typedef struct 		s_flags
{
	char		letter;
	int			valid;
	int			minus_sign_used;
	int			side;
	char		padding_char;
	int			width_enabled;
	int			width;
	int			width_negative;
	int			precision_enabled;
	int			precision;
	int			precision_negative;
	int			hashtag;
	int			hex__upper;
}					t_flags;

/*
** ___________ FUNCTION __________
*/

//void    ft_handle_flags(t_settings *settings, int i);

#endif
