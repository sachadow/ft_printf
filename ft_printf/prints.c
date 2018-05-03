/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:11:24 by sderet            #+#    #+#             */
/*   Updated: 2018/05/03 16:46:25 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>

void	printform(t_big *big, char *parse)
{
	int a;

	a = 0;
	while (big->lists.formats[a] != '\0')
	{
		if (*parse == big->lists.formats[a])
			big->fun_ptr[a](big, parse);
		a++;
	}
}

void	print_char(t_big *big, char *parse)
{
	uintmax_t	val;
	char		*c;

	if (*parse == 'C'  || big->lists.actual_len[0] == 'l')
		val = (wchar_t)va_arg(big->ap, void *);
	else
		val = (char)va_arg(big->ap, void *);
	c = ft_strnew(1);
	c[0] = val;
	ft_putstr(c);
	free(c);
}
