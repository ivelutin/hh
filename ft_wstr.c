/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:47:00 by ivelutin          #+#    #+#             */
/*   Updated: 2017/12/03 23:06:40 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

wchar_t	*ft_wstrdup(wchar_t *str)
{
	wchar_t	*dup;
	size_t	size;

	size = 0;
	while (str[size])
		++size;
	dup = (wchar_t *)malloc(sizeof(wchar_t) * (size + 1));
	if (!dup)
		return (NULL);
	size = -1;
	while (str[++size])
		dup[size] = str[size];
	dup[size] = '\0';
	return (dup);
}

size_t	ft_wstrlen(wchar_t *str)
{
	size_t count;
	size_t i;

	i = -1;
	count = 0;
	while (str[++i])
		count += ft_unicode_b(str[i]);
	return (count);
}

void	ft_prec_wstr(t_info *info, wchar_t *str)
{
	size_t count;
	size_t i;

	i = -1;
	count = 0;
	if (info->prec == -1)
		return ;
	if (ft_wstrlen(str) <= (size_t)info->prec)
		return ;
	while (str[++i] && count <= (size_t)info->prec)
		count += ft_unicode_b(str[i]);
	str[i - 1] = '\0';
}

char	*ft_wstr_to_str(wchar_t *wstr)
{
	char	*ret;
	size_t	i;
	size_t	pos;

	i = -1;
	pos = 0;
	ret = ft_strnew(ft_wstrlen(wstr));
	while (wstr[++i])
	{
		ft_unicode(wstr[i], ret + pos);
		pos += ft_unicode_b(wstr[i]);
	}
	return (ret);
}

void	ft_wstr(t_vec *vec, t_info *info, va_list vz)
{
	wchar_t *ctemp;
	char	*str;

	ctemp = NULL;
	str = 0;
	ft_easywstr(ctemp, vz, info, &str);
	ft_pad_handle(info, &str);
	ft_vec_append(vec, str);
	free(str);
}
