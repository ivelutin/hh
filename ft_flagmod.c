/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagmod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 03:04:05 by ivelutin          #+#    #+#             */
/*   Updated: 2017/12/02 09:27:27 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_mod(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	else
		return (0);
}

int		ft_fwidth(const char **format, t_info *info, va_list vz)
{
	if (**format == '*')
	{
		info->width = va_arg(vz, int);
		if (info->width < 0)
		{
			if (!(info->flags & LFT))
				info->flags ^= LFT;
			info->width = info->width * -1;
		}
		(*format)++;
		return (1);
	}
	return (0);
}

int		ft_fprec(const char **format, t_info *info, va_list vz)
{
	if (**format == '*')
	{
		info->prec = va_arg(vz, int);
		if (info->prec < -1)
			info->prec = -1;
		(*format)++;
		return (1);
	}
	return (0);
}

void	ft_flen(const char **format, t_info *info, const char *lengths, int i)
{
	i = ft_findchr(lengths, **format);
	if (i == 0)
	{
		if (*(*format + 1) == 'h')
			++*format;
		else
			i = 1;
	}
	if (i == 2)
		i = (*(*format + 1) == 'l') ? 3 : 2;
	info->length = MAX(i, info->length);
	++*format;
}
