/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:45:37 by sderet            #+#    #+#             */
/*   Updated: 2018/04/30 18:25:41 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include <stdlib.h>

char	*ft_printtype(char *parse, t_big *big)
{
	int		a;
	int b;

	a = 0;
	b = 0;
	put_flags(&(big->lists.actual_flags), parse, *big);
	while (inflags(parse[a], *big) == 1 && parse[a] != 0)
		a++;
	if (ft_isdigit(parse[a]))
		big->lists.minim = ft_atoi(&(parse[a]));
	while (ft_isdigit(parse[a]))
		a++;
	if (parse[a] == '.' && parse[++a] != 0)
		big->lists.prc = ft_atoi(&(parse[a]));
	while (ft_isdigit(parse[a]))
		a++;
	if (inlen(parse[a], *big) == 1)
		put_len(&(big->lists.actual_len), &(parse[a]), *big);
	while (b < 6)
	{
		if (ft_strncmp(&(parse[a]), big->lists.len[b],
					ft_strlen(big->lists.len[b])) == 0)
			a += ft_strlen(big->lists.len[b]);
		b++;
	}
//	if (informat(parse[a], *big))
//		printform(*big, parse[a]);
	return (parse + a + 1);
}

void	bigset(t_big *big)
{
	int a;

	a = -1;
	while (++a < 10)
		big->lists.actual_flags[a] = 0;
	a = -1;
	while (++a < 3)
		big->lists.actual_len[a] = 0;
	big->lists.minim = 0;
	big->lists.prc = 0;
}

int		ft_printf(const char *format, ...)
{
	char		*parse;
	char		*begin;
	char		*tmp;
	t_big		big;

	big.lists.len = (char**)malloc(sizeof(char*) * 6);
	big.lists.actual_flags = (char*)malloc(sizeof(char) * 10);
	big.lists.actual_len = (char*)malloc(sizeof(char) * 3);
	big.lists.formats = "sSpdDioOuUxXcC%";
	big.lists.flags = "#-+ 0";
	big.lists.len[0] = "hh";
	big.lists.len[1] = "h";
	big.lists.len[2] = "ll";
	big.lists.len[3] = "l";
	big.lists.len[4] = "j";
	big.lists.len[5] = "z";
	va_start(big.ap, format);
	parse = ft_strjoin(format, "");
	begin = parse;
	tmp = parse;
	while (*parse != 0)
	{
		if (*parse == '%')
		{
			bigset(&big);
			*parse = 0;
			ft_putstr(tmp);
			parse = ft_printtype((parse + 1), &(big));
			tmp = parse;
		}
		parse++;
	}
	ft_putstr(tmp);
	free(big.lists.actual_flags);
	free(big.lists.actual_len);
	free(big.lists.len);
	free(begin);
	return ((int)(parse - begin));
}