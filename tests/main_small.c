/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherelle <jherelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:44:39 by ecaceres          #+#    #+#             */
/*   Updated: 2020/02/06 20:39:57 by jherelle         ###   ########.fr       */
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

	X("%p", 0);
	X("%.0p", 0);
	X("%.0p", 18);
	X("%.050p", 123456);
	X("%20p", 123456);
	X("%10p", 123456);
	X("%5.2p", (void *)-1);
	X("%0-50p", 123456);
	X("%-50.20p", 123456);
	X("%.-20p", 123456);
	X("%.0*p", 3, 0);
	X("%010p", 0);
	X("%*.3p", 10, 0);
	X("%*.*p", 10, -15, 0);
	X("%*.*p", -15, -15, 0);
	X("%*.3p", 10, (void*)30);
	X("%03*p", 0, 0);



	/*
		si precision negative precision => width traité dans flags
		precision => 0 apres le x
		precision vient reduire la width
		precision avec flag 0 devient width

	*/
}
