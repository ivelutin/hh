/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:45:28 by ivelutin          #+#    #+#             */
/*   Updated: 2017/12/15 05:45:19 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		ft_num(t_vec *vec, t_info *info, va_list vz)
{
	intmax_t	ival;
	char		*str;

	ival = 0;
	ft_nif(info, ival, &str, vz);
	ft_prec_nums(info, &str);
	ft_pad_handle(info, &str);
	ft_vec_append(vec, str);
	free(str);
}

void		ft_octal(t_vec *vec, t_info *info, va_list vz)
{
	uintmax_t	oct;
	char		*str;

	if (info->spec == 'O')
		info->length = l;
	oct = ft_xou_len(info->length, vz);
	str = ft_uimaxtoa_base(oct, 8, "01234567");
	ft_handle_xou(&str, info);
	ft_vec_append(vec, str);
	free(str);
}

void		ft_hex(t_vec *vec, t_info *info, va_list vz)
{
	uintmax_t	hex;
	char		*str;

	if (info->spec == 'p')
		info->length = j;
	if (info->length)
	{
		hex = ft_xou_len(info->length, vz);
		str = ft_uimaxtoa_base(hex, 16, "0123456789abcdef");
	}
	if (info->spec == 'p' && info->flags & ZER && info->pset)
		info->flags ^= ZER;
	ft_handle_xou(&str, info);
	ft_vec_append(vec, str);
	free(str);
}

void		ft_uns(t_vec *vec, t_info *info, va_list vz)
{
	uintmax_t	uns;
	char		*str;

	if (info->spec == 'U')
		info->length = l;
	uns = ft_xou_len(info->length, vz);
	str = ft_uimaxtoa_base(uns, 10, "0123456789");
	ft_handle_xou(&str, info);
	ft_vec_append(vec, str);
	free(str);
}
