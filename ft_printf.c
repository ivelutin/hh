/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:45:50 by ivelutin          #+#    #+#             */
/*   Updated: 2017/12/15 06:29:06 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	ft_sprintf(const char *format, va_list vz, t_info info, t_vec *vec)
{
	size_t	i;

	while (*format)
	{
		i = 0;
		while (format[i] && format[i] != '%')
			i++;
		ft_vec_nappend(vec, (char *)format, i);
		format += i;
		if (*format == '%')
		{
			if (*(++format) == 0)
				break ;
			ft_handle_spec(vec, &format, &info, vz);
		}
		ft_info_init(&info);
	}
}

int			ft_strprintf(char **ret, const char *format, va_list vz)
{
	t_vec	vec;
	t_info	info;

	ft_info_init(&info);
	if (ft_vec_init(&vec, ft_strlen(format) + 50) == -1)
		return (-1);
	ft_sprintf(format, vz, info, &vec);
	*ret = ft_strndup(vec.data, vec.len);
	ft_vec_free(&vec);
	return (vec.len);
}

int			ft_vasprintf(char **ret, const char *format, va_list vz)
{
	if (*format == '\0')
		*ret = ft_strnew(0);
	if (!ret || !format || !*format)
		return (0);
	if (format && *format)
	{
		if (ft_strchr(format, '%') == NULL)
		{
			if ((*ret = ft_strdup(format)) == NULL)
				return (-1);
			return (ft_strlen(*ret));
		}
	}
	return (ft_strprintf(ret, format, vz));
}

int			ft_printf(const char *format, ...)
{
	va_list vz;
	int		len;
	char	*ret;

	if (!format || !*format)
		return (0);
	va_start(vz, format);
	if (!(len = ft_vasprintf(&ret, format, vz)))
		return (0);
	write(1, ret, len);
	free(ret);
	va_end(vz);
	return (len);
}
