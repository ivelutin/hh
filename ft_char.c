/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:45:04 by ivelutin          #+#    #+#             */
/*   Updated: 2017/12/03 20:06:27 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_unicode(wchar_t chr, char *str)
{
	if (chr < (MB_CUR_MAX == 1 ? 0xFF : 0x7F))
		str[0] = (unsigned char)chr;
	else if (chr < (1 << 11))
		bitmask_2bytes(chr, str);
	else if (chr < (1 << 16))
		bitmask_3bytes(chr, str);
	else if (chr < (1 << 21))
		bitmask_4bytes(chr, str);
}

int		ft_unicode_b(wchar_t chr)
{
	if (chr < (1 << 7))
		return (1);
	else if (chr < (1 << 11))
		return (2);
	else if (chr < (1 << 16))
		return (3);
	else if (chr < (1 << 21))
		return (4);
	return (0);
}

int		ft_wchar(char **str, va_list vz)
{
	wchar_t	chr;
	int		len;

	chr = va_arg(vz, wchar_t);
	len = ft_unicode_b(chr);
	*str = ft_strnew(len);
	ft_unicode(chr, *str);
	return (chr == '\0');
}

void	ft_null_chr(t_vec *vec, char *str)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(str);
	while (++i < len)
		if (str[i] == 1)
			str[i] = 0;
	ft_vec_nappend(vec, str, len);
}

void	ft_chr(t_vec *vec, t_info *info, va_list vz)
{
	char	chr;
	char	*str;
	int		null;

	if (info->spec == 'C' || info->length == l)
	{
		null = ft_wchar(&str, vz);
		str[0] = null ? null : str[0];
	}
	else
	{
		chr = va_arg(vz, int);
		str = ft_strnew(1);
		null = (chr == '\0') ? 1 : 0;
		str[0] = chr + null;
	}
	ft_pad_handle(info, &str);
	if (null)
		ft_null_chr(vec, str);
	else
		ft_vec_append(vec, str);
	free(str);
}
