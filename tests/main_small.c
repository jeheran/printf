/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <jherelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:44:39 by ecaceres          #+#    #+#             */
/*   Updated: 2020/02/07 14:49:54 by jherelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"

#ifndef DEBUG
# define DEBUG 0
#endif

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

int
	main(int argc, char **argv)
{
	int r1;
	int r2;

	g_debug = DEBUG;

	X("%.0x", 123);
	X("%d", 0);
	X("%d", -2147483647 - 1);

	X("%%", 0);
	X("%%", 'a');
	X("%%", 'b');
	X("%%", '9');
	X("%%", 227);
	X("%-%", 0);
	X("%0%", 0);
	X("%3%", 0);
	X("%10b", 0);



	/*
		si precision negative precision => width traité dans flags
		precision => 0 apres le x
		precision vient reduire la width
		precision avec flag 0 devient width

	*/
}
