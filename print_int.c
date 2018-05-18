/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:18:39 by sderet            #+#    #+#             */
/*   Updated: 2018/05/18 18:46:17 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(t_big *big, char *parse)
{
	int		val;
	char	*str;
	int		a;
	int		plus;
	int		space;

	parse += 0;
	plus = 0;
	space = ' ';
	if (ft_strcmp(big->lists.actual_len, "h") == 0)
		val = (short int)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "hh") == 0)
		val = (char)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "j") == 0)
		val = (intmax_t)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "z") == 0)
		val = (ssize_t)va_arg(big->ap, void *);
	else if (ft_strcmp(big->lists.actual_len, "l") == 0)
	{
		big->fun_ptr[4](big, parse);
		return ;
	}
	else if (ft_strcmp(big->lists.actual_len, "ll") == 0)
	{
		big->fun_ptr[4](big, parse);
		return ;
	}
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
		ft_putchar('+');
	if (val < 0 && space == '0')
		ft_putchar('-');
	if (inacflags(' ', *big) && !inacflags('+', *big) && val > 0)
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
		ft_putchar('+');
	if (val < 0 && space == ' ')
		ft_putchar('-');
	ft_putstr((val < 0 ? str + 1 : str));
	while (inacflags('-', *big) && big->lists.minim > a)
	{
		a++;
		ft_putchar(' ');
	}
	big->nbprint += a;
}

void	print_up_int(t_big *big, char *parse)
{
	unsigned int	val;
	char			*str;
	int				a;
	int				plus;
	int				space;

	parse += 0;
	plus = 0;
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
	str = ft_uitoa((unsigned long)val);
	a = ft_strlen(str);
	if (inacflags('0', *big))
		space = '0';
	if (inacflags('+', *big))
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
	big->nbprint += a;
}
