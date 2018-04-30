/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_fun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:59:50 by sderet            #+#    #+#             */
/*   Updated: 2018/04/30 17:14:02 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Indicates wether the character 'parse' is in the list of flags for
**	this version of ft_printf
*/

int		inflags(char parse, t_big big)
{
	int a;

	a = 0;
	while (big.lists.flags[a] != 0)
	{
		if (parse == big.lists.flags[a])
			return (1);
		a++;
	}
	return (0);
}

/*
**	Indicates wether the character 'parse' is in the list of length modifiers
**	for this version of ft_printf
*/

int		inlen(char parse, t_big big)
{
	int a;

	a = 0;
	while (a < 6)
	{
		if (ft_strncmp(&parse, big.lists.len[a],
					ft_strlen(big.lists.len[a])) == 0)
			return (1);
		a++;
	}
	return (0);
}

/*
**	Indicates wether the character 'parse' is in the list of formats for
**	this version of ft_printf
*/

int		informat(char parse, t_big big)
{
	int a;

	a = 0;
	while (big.lists.formats[a] != 0)
	{
		if (parse == big.lists.formats[a])
			return (1);
		a++;
	}
	return (0);
}

/*
**	Puts flags in actual_flags based on the ones in big.lists.flags
*/

void	put_flags(char **actual_flags, char *parse, t_big big)
{
	int a;

	a = 0;
	while (inflags(parse[a], big) == 1)
		a++;
	ft_strncpy(*actual_flags, parse, a);
}

/*
**	Puts length modifiers in actual_len based on the ones in big.lists.len
*/

void	put_len(char **actual_len, char *parse, t_big big)
{
	int a;

	a = 0;
	while (a < 6)
	{
		if (ft_strncmp(parse, big.lists.len[a],
					ft_strlen(big.lists.len[a])) == 0)
			ft_strncpy(*actual_len, parse, ft_strlen(big.lists.len[a]));
		a++;
	}
}
