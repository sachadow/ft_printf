/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:21:10 by sderet            #+#    #+#             */
/*   Updated: 2018/04/30 15:28:07 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

/*
**	Structure qui donne differentes infos sur ce qu'on fait, et qui contient
**	les pointeurs sur les fonctions d'affichage.
**	formats : conversions de base, contient tout ce que l'on gere
**	flags : les 'vrais' flags, donc #, 0, +, etc
**	len : les autres flags, l, ll, h, etc
**
**	Les fonctions fun_ptr affichent des characteres selon les sflags
**	et le flags. Ils retournent un pointeur vers le prochain charactere a
**	afficher apres la fin du format.
*/
typedef struct	s_format
{
	char	*formats;
	char	*flags;
	char	**len;
	int		minim;
	int		prc;
	char	*actual_flags;
	char	*actual_len;
}				t_format;

typedef struct	s_big
{
	va_list		ap;
	t_format	lists;
	char		(*fun_ptr[14])(char *parse, struct s_big big, va_list ap);
}				t_big;

int				ft_printf(const char *format, ...);

int				inflags(char parse, t_big big);

int				inlen(char parse, t_big big);

int				informat(char parse, t_big big);

void			put_flags(char *actual_flags[10], char *parse, t_big big);

void			put_len(char *actual_len[3], char *parse, t_big big);

#endif
