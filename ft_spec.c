/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:45:14 by ivelutin          #+#    #+#             */
/*   Updated: 2017/12/12 18:52:05 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_convtbl g_convtbl[] =
{
	{'d', &ft_num},
	{'D', &ft_num},
	{'i', &ft_num},
	{'p', &ft_hex},
	{'o', &ft_octal},
	{'O', &ft_octal},
	{'x', &ft_hex},
	{'X', &ft_hex},
	{'u', &ft_uns},
	{'U', &ft_uns},
	{'s', &ft_str},
	{'S', &ft_wstr},
	{'c', &ft_chr},
	{'C', &ft_chr},
	{'f', &ft_float},
	{'%', &ft_pct}
};

void	ft_get(t_vec *vec, t_info *info, va_list vz)
{
	int i;

	i = -1;
	while (++i < 16)
	{
		if (info->spec == g_convtbl[i].spec)
		{
			g_convtbl[i].f(vec, info, vz);
			return ;
		}
	}
	ft_pct(vec, info, vz);
}

void	ft_handle_spec(t_vec *vec, const char **format,
													t_info *info, va_list vz)
{
	while (1)
	{
		if (ft_flags(format, info))
			continue ;
		if (ft_width(format, info, vz))
			continue ;
		if (ft_prec(format, info, vz))
			continue ;
		if (ft_len(format, info))
			continue ;
		if (**format == '\0')
			return ;
		info->spec = *(*format)++;
		break ;
	}
	ft_get(vec, info, vz);
}

void	ft_pct(t_vec *vec, t_info *info, va_list vz)
{
	char *str;

	(void)vz;
	str = ft_strnew(1);
	*str = info->spec;
	ft_pad_handle(info, &str);
	ft_vec_append(vec, str);
	free(str);
}
