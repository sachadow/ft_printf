/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:06:01 by sderet            #+#    #+#             */
/*   Updated: 2018/05/25 18:00:16 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdio.h>
#include "ft_printf.h"

int main(int argc, char **argv)
{
	int a;
	char *test;

	test = "test";
	argc += 0;
	a = ft_printf(argv[1], -2147483649, 2, 3);
	printf("\n%d\n", a);
	a = printf(argv[1], -2147483649, 2, 3);
	printf("\n%d\n", a);
	return (0);
}
