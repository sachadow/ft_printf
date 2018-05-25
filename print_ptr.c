/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:05:10 by sderet            #+#    #+#             */
/*   Updated: 2018/05/25 17:07:02 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ptr(t_big *big, char *parse)
{
	char			*base;
	unsigned long	val;
	char			result[9];
	int				a;
	char			space;

	parse += 0;
	a = 8;
	space = ' ';
	big->compteur = 11;
	val = (unsigned long)va_arg(big->ap, void *);
	base = "0123456789abcdef";
	while ((val / 16) > 0 || a >= 8)
	{
		result[a] = base[(val % 16)];
		val /= 16;
		a--;
	}
	result[a] = base[(val % 16)];
	if (inacflags('0', *big))
		space = '0';
	while (!inacflags('-', *big) && big->lists.minim > big->compteur &&
			space == ' ')
	{
		big->compteur++;
		ft_putchar(space);
	}
	ft_putstr("0x");
	while (!inacflags('-', *big) && big->lists.minim > big->compteur &&
			space == '0')
	{
		big->compteur++;
		ft_putchar(space);
	}
	a = -1;
	while (++a < 9)
		ft_putchar(result[a]);
	while (inacflags('-', *big) && big->lists.minim > big->compteur)
	{
		big->compteur++;
		ft_putchar(' ');
	}
	big->nbprint += big->compteur;
}

void	print_hex(t_big *big, char *parse)
{
	char			*base;
	unsigned long	val;
	char			result[1 + (sizeof(unsigned long) * CHAR_BIT + 2) / 3 + 1];
	int				a;
	char			space;

	parse += 0;
	space = ' ';
	if (ft_strcmp(big->lists.actual_len, "h") == 0)
		val = (unsigned short int)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "hh") == 0)
		val = (unsigned char)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "l") == 0)
		val = (unsigned long int)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "ll") == 0)
		val = (unsigned long long int)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "j") == 0)
		val = (uintmax_t)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "z") == 0)
		val = (size_t)va_arg(big->ap, void *);
	else
		val = (unsigned int)va_arg(big->ap, void *);
	base = "0123456789abcdef";
	a = 1 + (sizeof(val) * CHAR_BIT + 2) / 3 + 1;
	result[--a] = '\0';
	while(val != 0 || a == (sizeof(val) * CHAR_BIT + 2) / 3 + 1)
	{
		result[--a] = base[val % 16];
		val /= 16;
	}
	big->compteur = ft_strlen(result + a);
	if (inacflags('#', *big))
		big->compteur += 2;
	if (inacflags('0', *big))
		space = '0';
	while (!inacflags('-', *big) && big->lists.minim > big->compteur &&
			space == ' ')
	{
		big->compteur++;
		ft_putchar(space);
	}
	while (!inacflags('-', *big) && big->lists.minim > big->compteur &&
			space == '0')
	{
		big->compteur++;
		ft_putchar(space);
	}
	if (inacflags('#', *big))
		ft_putstr("0x");
	a--;
	while (result[++a] != 0)
		ft_putchar(result[a]);
	while (inacflags('-', *big) && big->lists.minim > big->compteur)
	{
		big->compteur++;
		ft_putchar(' ');
	}
	big->nbprint += big->compteur;
}

void	print_up_hex(t_big *big, char *parse)
{
	char			*base;
	unsigned long	val;
	char			result[1 + (sizeof(unsigned long) * CHAR_BIT + 2) / 3 + 1];
	int				a;
	char			space;

	parse += 0;
	space = ' ';
	if (ft_strcmp(big->lists.actual_len, "h") == 0)
		val = (unsigned short int)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "hh") == 0)
		val = (unsigned char)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "l") == 0)
		val = (unsigned long int)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "ll") == 0)
		val = (unsigned long long int)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "j") == 0)
		val = (uintmax_t)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "z") == 0)
		val = (size_t)va_arg(big->ap, void *);
	else
		val = (unsigned int)va_arg(big->ap, void *);
	base = "0123456789ABCDEF";
	a = 1 + (sizeof(val) * CHAR_BIT + 2) / 3 + 1;
	result[--a] = '\0';
	while(val != 0 || a == (sizeof(val) * CHAR_BIT + 2) / 3 + 1)
	{
		result[--a] = base[val % 16];
		val /= 16;
	}
	big->compteur = ft_strlen(result + a);
	if (inacflags('#', *big))
		big->compteur += 2;
	if (inacflags('0', *big))
		space = '0';
	while (!inacflags('-', *big) && big->lists.minim > big->compteur &&
			space == ' ')
	{
		big->compteur++;
		ft_putchar(space);
	}
	while (!inacflags('-', *big) && big->lists.minim > big->compteur &&
			space == '0')
	{
		big->compteur++;
		ft_putchar(space);
	}
	if (inacflags('#', *big))
		ft_putstr("0X");
	a--;
	while (result[++a] != 0)
		ft_putchar(result[a]);
	while (inacflags('-', *big) && big->lists.minim > big->compteur)
	{
		big->compteur++;
		ft_putchar(' ');
	}
	big->nbprint += big->compteur;
}

void	print_oct(t_big *big, char *parse)
{
	char			*base;
	unsigned long	val;
	char			result[1 + (sizeof(unsigned long) * CHAR_BIT + 2) / 3 + 1];
	int				a;
	char			space;

	parse += 0;
	space = ' ';
	if (ft_strcmp(big->lists.actual_len, "h") == 0)
		val = (unsigned short int)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "hh") == 0)
		val = (unsigned char)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "l") == 0)
		val = (unsigned long int)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "ll") == 0)
		val = (unsigned long long int)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "j") == 0)
		val = (uintmax_t)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "z") == 0)
		val = (size_t)va_arg(big->ap, void *);
	else
		val = (unsigned int)va_arg(big->ap, void *);
	base = "012345678";
	a = 1 + (sizeof(val) * CHAR_BIT + 2) / 3 + 1;
	result[--a] = '\0';
	while(val != 0 || a == (sizeof(val) * CHAR_BIT + 2) / 3 + 1)
	{
		result[--a] = base[val % 8];
		val /= 8;
	}
	big->compteur = ft_strlen(result + a);
	if (inacflags('0', *big))
		space = '0';
	while (!inacflags('-', *big) && big->lists.minim > big->compteur &&
			space == ' ')
	{
		big->compteur++;
		ft_putchar(space);
	}
	while (!inacflags('-', *big) && big->lists.minim > big->compteur &&
			space == '0')
	{
		big->compteur++;
		ft_putchar(space);
	}
	a--;
	while (result[++a] != 0)
		ft_putchar(result[a]);
	while (inacflags('-', *big) && big->lists.minim > big->compteur)
	{
		big->compteur++;
		ft_putchar(' ');
	}
	big->nbprint += big->compteur;
}

void	print_up_oct(t_big *big, char *parse)
{
	char			*base;
	unsigned long	val;
	char			result[1 + (sizeof(unsigned long) * CHAR_BIT + 2) / 3 + 1];
	int				a;
	char			space;

	parse += 0;
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
		val = (ssize_t)va_arg(big->ap, void *);
	else
		val = (int)va_arg(big->ap, void *);
	base = "012345678";
	a = 1 + (sizeof(val) * CHAR_BIT + 2) / 3 + 1;
	result[--a] = '\0';
	while(val != 0 || a == (sizeof(val) * CHAR_BIT + 2) / 3 + 1)
	{
		result[--a] = base[val % 8];
		val /= 8;
	}
	big->compteur = ft_strlen(result + a);
	if (inacflags('0', *big))
		space = '0';
	while (!inacflags('-', *big) && big->lists.minim > big->compteur &&
			space == ' ')
	{
		big->compteur++;
		ft_putchar(space);
	}
	while (!inacflags('-', *big) && big->lists.minim > big->compteur &&
			space == '0')
	{
		big->compteur++;
		ft_putchar(space);
	}
	a--;
	while (result[++a] != 0)
		ft_putchar(result[a]);
	while (inacflags('-', *big) && big->lists.minim > big->compteur)
	{
		big->compteur++;
		ft_putchar(' ');
	}
	big->nbprint += big->compteur;
}

