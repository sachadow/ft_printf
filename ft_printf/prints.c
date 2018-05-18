/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:11:24 by sderet            #+#    #+#             */
/*   Updated: 2018/05/16 18:40:05 by sderet           ###   ########.fr       */
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
	ft_putchar('%');
	big->nbprint++;
}

void	print_int(t_big *big, char *parse)
{
	int		val;
	char	*str;
	int		a;
	int		plus;
	int		space;

	plus = 0;
	space = ' ';
	if (ft_strcmp(big->lists.actual_len, "h") == 0)
		val = (short int)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "hh") == 0)
		val = (char)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "l") == 0)
		val = (long int)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "ll") == 0)
		val = (long long int)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "j") == 0)
		val = (intmax_t)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "z") == 0)
		val = (size_t)va_arg(big->ap, void *);
	else
		val = (int)va_arg(big->ap, void *);
	str = ft_itoa((int)val);
	a = ft_strlen(str);
	if (inacflags('0', *big))
		space = '0';
	if (inacflags('+', *big) && val >= 0)
	{
		a++;
		plus++;
	}
	if (plus != 0 && space == '0')
		ft_putstr("+");
	if (inacflags(' ', *big) && !inacflags('+', *big))
	{
		a++;
		ft_putchar(' ');
	}
	while (!inacflags('-', *big) && big->lists.minim > a)
	{
		a++;
		ft_putchar(space);
	}
	if (plus != 0 && space == ' ')
		ft_putstr("+");
	ft_putstr(str);
	while (inacflags('-', *big) && big->lists.minim > a)
	{
		a++;
		ft_putchar(' ');
	}
	free(str);
	big->nbprint += a;
}

void	print_char(t_big *big, char *parse)
{
	uintmax_t	val;
	char		*c;

	if (*parse == 'C' || ft_strcmp(big->lists.actual_len, "l") == 0)
		val = (wint_t)va_arg(big->ap, void *);
	else
		val = (char)va_arg(big->ap, void *);
	ft_putchar((char)val);
	big->nbprint++;
}
