/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <jherelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:02:24 by jherelle          #+#    #+#             */
/*   Updated: 2020/02/11 11:08:46 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define FORMAT_TYPES "cspdiuxX%"
# define FLAGS_CHARS "-*.0123456789"
# define FD 1

/*
** ___________ STRUCTURES __________
*/
typedef struct	s_settings
{
	int			written;
	const char	*format;
	va_list		parameters;
}				t_settings;

typedef struct	s_flags
{
	int			padding_left_minus_sign;
	int			width_on;
	int			width;
	char		pading_character;
	int			precision_on;
	int			precision;
	int			precision_neg;
	char		conv;
}				t_flags;

/*
** ___________ FUNCTION __________
*/

int				ft_handle_flags(t_settings *settings, int i);
void			ft_printf_conv_handler(t_settings *settings,
										t_flags *flags, char conv);
void			ft_printf_conv_s(t_settings *settings,
										t_flags *flags, int *i);
void			ft_printf_conv_p(t_settings *settings,
										t_flags *flags, int *i);
void			ft_printf_conv_x(t_settings *settings,
										t_flags *flags, int *i, char conv);
void			ft_printf_conv_u(t_settings *settings,
										t_flags *flags, int *i);
void			ft_printf_conv_d_i(t_settings *settings,
										t_flags *flags, int *i);
void			ft_printf_conv_c_else(t_settings *settings,
										t_flags *flags, char car, int *i);
void			ft_printf_width_ints(t_settings *settings,
										t_flags *flags, int *len, int neg);
void			ft_printf_width_neg_ints(t_settings *settings,
										t_flags *flags, int *len, int neg);

#endif
