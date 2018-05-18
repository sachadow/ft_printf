/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:06:35 by sderet            #+#    #+#             */
/*   Updated: 2018/05/17 17:06:49 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_big *big, char *parse)
{
	char	val;
	int		a;
	char	space;

	a = 1;
	space = ' ';
	if (*parse == 'C' || ft_strcmp(big->lists.actual_len, "l") == 0)
		val = (wint_t)va_arg(big->ap, void *);
	else
		val = (char)va_arg(big->ap, void *);
	if (inacflags('0', *big))
		space = '0';
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
	ft_putchar(val);
	while (inacflags('-', *big) && big->lists.minim > a)
	{
		a++;
		ft_putchar(' ');
	}
	big->nbprint += a;
}
