/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:21:10 by sderet            #+#    #+#             */
/*   Updated: 2018/05/18 17:02:57 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>
#include <wchar.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

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
	int			nbprint;
	va_list		ap;
	t_format	lists;
	int			compteur;
	void		(*fun_ptr[15])(struct s_big *big, char *parse);
}				t_big;

int				ft_printf(const char *format, ...);

int				inflags(char parse, t_big big);

int				inacflags(char parse, t_big big);

int				inlen(char parse, t_big big);

int				informat(char parse, t_big big);

void			put_flags(char *actual_flags[10], char *parse, t_big big);

void			put_len(char *actual_len[3], char *parse, t_big big);

void			printform(t_big *big, char *parse);

void			print_char(t_big *big, char *parse);

void			print_int(t_big *big, char *parse);

void			print_up_int(t_big *big, char *parse);

void			print_percent(t_big *big, char *parse);

void			print_string(t_big *big, char *parse);

void			print_up_string(t_big *big, char *parse);

void			print_ptr(t_big *big, char *parse);

void			print_hex(t_big *big, char *parse);

void			print_oct(t_big *big, char *parse);

void			print_up_hex(t_big *big, char *parse);

void			print_up_oct(t_big *big, char *parse);

#endif
