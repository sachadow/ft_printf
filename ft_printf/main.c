/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:06:01 by sderet            #+#    #+#             */
/*   Updated: 2018/05/16 18:33:42 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdio.h>
#include "ft_printf.h"

int main(int argc, char **argv)
{
	int a;
	a = ft_printf(argv[1], 'y', 'c', 25);
	printf("\n%d\n", a);
	a = printf(argv[1], 'y', 'c', 25);
	printf("\n%d\n", a);
	return (0);
}
