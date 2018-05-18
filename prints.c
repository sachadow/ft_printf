/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:11:24 by sderet            #+#    #+#             */
/*   Updated: 2018/05/18 15:50:01 by sderet           ###   ########.fr       */
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

void	print_percent(t_big *big, char *parse)
{
	parse += 0;
	ft_putchar('%');
	big->nbprint++;
}


void	print_string(t_big *big, char *parse)
{
	char	*val;
	int		a;
	char	space;

	if (*parse == 'S' || ft_strcmp(big->lists.actual_len, "l") == 0)
		print_up_string(big, parse);
	else
	{
		val = (char *)va_arg(big->ap, void *);
		big += 0;
		space = ' ';
		a = ft_strlen(val);
		if (inacflags('0', *big))
			space = '0';
		while (!inacflags('-', *big) && big->lists.minim > a)
		{
			a++;
			ft_putchar(space);
		}
		ft_putstr(val);
		while (inacflags('-', *big) && big->lists.minim > a)
		{
			a++;
			ft_putchar(' ');
		}
		big->nbprint += a;
	}
}

int		ft_wstrlen(wchar_t *str)
{
	int a;

	a = 0;
	while (str[a] != 0)
		a++;
	return (a);
}

void	ft_putwstr(wchar_t *str)
{
	int a;

	a = 0;
	while (str[a] != 0)
	{
		write(1, &(str[a]), 1);
		a++;
	}
}

void	print_up_string(t_big *big, char *parse)
{
	wchar_t	*val;
	int		a;
	char	space;

	val = (wchar_t *)va_arg(big->ap, void *);
	big += 0;
	parse += 0;
	space = ' ';
	a = ft_wstrlen(val);
	if (inacflags('0', *big))
		space = '0';
	while (!inacflags('-', *big) && big->lists.minim > a)
	{
		a++;
		ft_putchar(space);
	}
	ft_putwstr(val);
	while (inacflags('-', *big) && big->lists.minim > a)
	{
		a++;
		ft_putchar(' ');
	}
	big->nbprint += a;
}
