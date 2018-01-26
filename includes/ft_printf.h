/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:54:56 by ivelutin          #+#    #+#             */
/*   Updated: 2018/01/18 12:08:58 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct	s_vec
{
	size_t		len;
	size_t		cap;
	char		*data;
}				t_vec;

typedef enum	e_lenmod
{
	hh,
	h,
	l,
	ll,
	j,
	z
}				t_lenmod;

typedef enum	e_flag
{
	LFT = 1 << 0,
	POS = 1 << 1,
	INV = 1 << 2,
	ZER = 1 << 3,
	HTG = 1 << 4
}				t_flag;

typedef enum	e_bool
{
	false,
	true
}				t_bool;

typedef struct	s_info
{
	char		flags;
	char		length;
	char		spec;
	int			width;
	int			prec;
	int			pset:1;
	int			wstr;
}				t_info;

typedef struct	s_convtbl
{
	char spec;
	void (*f)(t_vec *, t_info *, va_list);
}				t_convtbl;

/*
** ft_bonus.c
*/
void			ft_binary(t_vec *vec, t_info *info, va_list vz);
intmax_t		*ft_printf_n_len(t_info *info, va_list vz);
void			ft_none(t_vec *vec, t_info *info, va_list vz);

/*
** ft_char.c
*/
void			ft_unicode(wchar_t chr, char *str);
int				ft_unicode_b(wchar_t chr);
int				ft_wchar(char **str, va_list vz);
void			ft_null_chr(t_vec *vec, char *str);
void			ft_chr(t_vec *vec, t_info *info, va_list vz);

/*
** ft_handle.c
*/
void			ft_prec_nums(t_info *info, char **str);
void			ft_prec_handle(t_info *info, char **str);
void			ft_right_just(t_info *info, char **str, char *new);
void			ft_pad_handle(t_info *info, char **str);

/*
** ft_num.c
*/
void			ft_num(t_vec *vec, t_info *info, va_list vz);
void			ft_octal(t_vec *vec, t_info *info, va_list vz);
void			ft_hex(t_vec *vec, t_info *info, va_list vz);
void			ft_uns(t_vec *vec, t_info *info, va_list vz);

/*
** ft_parse.c
*/
t_bool			ft_flags(const char **format, t_info *info);
t_bool			ft_width(const char **format, t_info *info, va_list vz);
t_bool			ft_prec(const char **format, t_info *info, va_list vz);
t_bool			ft_len(const char **format, t_info *info);

/*
** ft_printf.c
*/
int				ft_printf(const char *format, ...);
int				ft_vasprintf(char **ret, const char *format, va_list vz);
int				ft_strprintf(char **ret, const char *format, va_list vz);

/*
** ft_spec.c
*/
void			ft_get(t_vec *vec, t_info *info, va_list vz);
void			ft_handle_spec(t_vec *vec, const char **format,
												t_info *info, va_list vz);
void			ft_pct(t_vec *vec, t_info *info, va_list vz);

/*
** ft_str.c
*/
char			*ft_null_str(t_info *info);
void			ft_str(t_vec *vec, t_info *info, va_list vz);

/*
** ft_vector.c
*/
void			ft_vec_append(t_vec *vec, char *newdata);
void			ft_vec_resize(t_vec *vec, size_t min);
void			ft_vec_nappend(t_vec *vec, char *newdata, size_t n);
void			ft_vec_free(t_vec *vec);

/*
** ft_wstr.c
*/
wchar_t			*ft_wstrdup(wchar_t *str);
size_t			ft_wstrlen(wchar_t *str);
void			ft_prec_wstr(t_info *info, wchar_t *str);
char			*ft_wstr_to_str(wchar_t *wstr);
void			ft_wstr(t_vec *vec, t_info *info, va_list vz);

/*
** ft_xou.c
*/
uintmax_t		ft_xou_len(char length, va_list vz);
void			ft_handle_alt(t_info *info, char **str);
void			ft_x_toupper(char *str, char spec);
void			ft_handle_xou(char **str, t_info *info);

/*
** ft_init.c
*/
void			ft_info_init(t_info *info);
int				ft_vec_init(t_vec *vec, size_t init_cap);
intmax_t		ft_int_len(char length, va_list vz);
void			ft_float(t_vec *vec, t_info *info, va_list vz);

/*
** ft_flagmod.c
*/
int				ft_mod(char c);
int				ft_fwidth(const char **format, t_info *info, va_list vz);
int				ft_fprec(const char **format, t_info *info, va_list vz);
void			ft_flen(const char **format, t_info *info, const char *lengths,
																		int i);

/*
** ft_bitmask.c
*/
void			bitmask_2bytes(wchar_t chr, char *str);
void			bitmask_3bytes(wchar_t chr, char *str);
void			bitmask_4bytes(wchar_t chr, char *str);

/*
** ft_ladilla.c
*/
void			ft_nif(t_info *info, intmax_t ival, char **str, va_list vz);
int				ft_pnum(char extra, char **new, t_info *info, char **str);
void			ft_rjif(char extra, char *new, t_info *info, char **str);
void			ft_rjelse(char *new, t_info *info, char **str);
void			ft_easywstr(wchar_t *ctemp, va_list vz, t_info *info,
																	char **str);
/*
** ft_clxou.c
*/
void			ft_clhand_alt(t_info *info, char **str, char **new);
void			ft_clhand_xou(t_info *info, char **str);

#endif
