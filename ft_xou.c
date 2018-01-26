/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xou.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:47:09 by ivelutin          #+#    #+#             */
/*   Updated: 2018/01/19 15:05:53 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

uintmax_t	ft_xou_len(char len, va_list vz)
{
	if (len == hh || len == h || len == l || len == ll || len == j || len == z)
	{
		if (len == hh)
			return ((unsigned char)va_arg(vz, int));
		else if (len == h)
			return ((unsigned short)va_arg(vz, int));
		else if (len == l)
			return (va_arg(vz, unsigned long));
		else if (len == ll)
			return (va_arg(vz, unsigned long long));
		else if (len == j)
			return (va_arg(vz, uintmax_t));
		else if (len == z)
			return (va_arg(vz, size_t));
	}
	else
		return (va_arg(vz, unsigned int));
}

void		ft_handle_alt(t_info *info, char **str)
{
	char *new;

	if (!(info->spec == 'x' || info->spec == 'X' ||
		info->spec == 'o' || info->spec == 'O' || info->spec == 'p'
			|| info->spec == 'b'))
		return ;
	new = ft_strdup(*str);
	if (info->spec == 'p')
		ft_insrt_to_str(&new, "0x");
	else if (info->flags & HTG)
		ft_clhand_alt(info, str, &new);
	free(*str);
	*str = new;
}

void		ft_x_toupper(char *str, char spec)
{
	if (spec != 'X')
		return ;
	while (*str)
	{
		if (ft_isalpha(*str))
			*str = ft_toupper(*str);
		str++;
	}
}

void		ft_handle_xou(char **str, t_info *info)
{
	if (info->flags & ZER && info->prec == 0)
		info->flags ^= ZER;
	if (info->prec == 0 && !ft_strcmp(*str, "0"))
		**str = '\0';
	ft_prec_nums(info, str);
	ft_clhand_xou(info, str);
	ft_x_toupper(*str, info->spec);
}
