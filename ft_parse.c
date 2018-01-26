/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:44:51 by ivelutin          #+#    #+#             */
/*   Updated: 2018/01/18 12:09:09 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_bool		ft_flags(const char **format, t_info *info)
{
	const char	flags[] = "-+ 0#";
	size_t		i;

	i = 0;
	while (flags[i] != **format && flags[i])
		i++;
	if (flags[i] && **format)
	{
		info->flags = info->flags | (1 << i);
		(*format)++;
		return (true);
	}
	else
		return (false);
}

t_bool		ft_width(const char **format, t_info *info, va_list vz)
{
	int res;

	res = 0;
	if (ft_fwidth(format, info, vz))
		return (true);
	if (!ft_isdigit(**format))
		return (false);
	while (ft_isdigit(**format))
	{
		res = res * 10 + (**format - '0');
		(*format)++;
	}
	info->width = res;
	return (true);
}

t_bool		ft_prec(const char **format, t_info *info, va_list vz)
{
	int res;

	res = 0;
	if (**format != '.')
		return (false);
	info->pset = 1;
	(*format)++;
	if (ft_fprec(format, info, vz))
		return (true);
	while (ft_isdigit(**format))
	{
		res = res * 10 + (**format - '0');
		(*format)++;
	}
	info->prec = res;
	return (true);
}

t_bool		ft_len(const char **format, t_info *info)
{
	const char	lengths[] = "hhlljz";
	int			i;

	i = 0;
	if (ft_mod(**format))
	{
		ft_flen(format, info, lengths, i);
		return (true);
	}
	return (false);
}
