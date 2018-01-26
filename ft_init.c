/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:00:39 by ivelutin          #+#    #+#             */
/*   Updated: 2018/01/25 17:19:53 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		ft_info_init(t_info *info)
{
	info->width = 0;
	info->prec = -1;
	info->spec = 'N';
	info->flags = 0;
	info->length = -1;
	info->pset = 0;
}

int			ft_vec_init(t_vec *vec, size_t init_cap)
{
	if (!vec || !init_cap)
		return (-1);
	vec->len = 0;
	vec->cap = init_cap;
	if ((vec->data = ft_memalloc(sizeof(char) * vec->cap)) == NULL)
		return (-1);
	return (0);
}

intmax_t	ft_int_len(char len, va_list vz)
{
	if (len == hh || len == h || len == l || len == ll || len == j || len == z)
	{
		if (len == hh)
			return ((signed char)va_arg(vz, int));
		else if (len == h)
			return ((short)va_arg(vz, int));
		else if (len == l)
			return (va_arg(vz, long));
		else if (len == ll)
			return (va_arg(vz, long long));
		else if (len == j)
			return (va_arg(vz, intmax_t));
		else if (len == z)
			return (va_arg(vz, ssize_t));
	}
	return (va_arg(vz, int));
}

void		ft_float(t_vec *vec, t_info *info, va_list vz)
{
	(void)vec;
	(void)info;
	(void)vz;
}
