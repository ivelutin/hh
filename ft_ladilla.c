/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ladilla.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 05:08:20 by ivelutin          #+#    #+#             */
/*   Updated: 2018/01/18 12:09:02 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_nif(t_info *info, intmax_t ival, char **str, va_list vz)
{
	if (info->spec == 'D')
		info->length = l;
	if (info->spec == 'i' || info->spec == 'D')
		info->spec = 'd';
	ival = ft_int_len(info->length, vz);
	*str = ft_imaxtoa(ival);
	if (info->prec != -1 && info->flags & ZER)
		info->flags ^= ZER;
	if (info->prec == 0 && !ft_strcmp("0", *str))
		**str = '\0';
	if (((info->flags & POS || info->flags & INV) && *str[0] != '-')
														&& info->spec == 'd')
	{
		ft_insrt_to_str(str, (info->flags & INV) ? " " : "+");
		*str[0] = ((info->flags & POS)) ? '+' : *str[0];
	}
}

int		ft_pnum(char extra, char **new, t_info *info, char **str)
{
	if (info->prec == 0 && !ft_strcmp("0", *str))
	{
		**str = '\0';
		return (1);
	}
	if (info->prec == -1)
		info->prec = 1;
	if ((size_t)info->prec < ft_strlen(*str))
		return (1);
	extra = (!ft_isdigit((*str)[0]) && info->spec == 'd') ? (*str)[0] : 0;
	if (extra)
		(*str)++;
	*new = ft_strnew(info->prec + !!extra);
	ft_memset(*new + !!extra, '0', info->prec - ft_strlen(*str));
	ft_strcpy(*new + info->prec - ft_strlen(*str) + !!extra, *str);
	if (extra)
		(*new)[0] = extra;
	return (0);
}

void	ft_rjif(char extra, char *new, t_info *info, char **str)
{
	extra = (!ft_isdigit((*str)[0]) && info->spec == 'd') ? (*str)[0] : 0;
	ft_memset(new, '0', info->width - ft_strlen(*str) + !!extra);
	if (extra)
	{
		new[0] = extra;
		(*str)[0] = '0';
	}
}

void	ft_rjelse(char *new, t_info *info, char **str)
{
	ft_memset(new, ' ', info->width - ft_strlen(*str));
	if ((info->flags & POS) && **str != '-')
		new[info->width - ft_strlen(*str)] =
											((*str)[0] == '-') ? '-' : '+';
}

void	ft_easywstr(wchar_t *ctemp, va_list vz, t_info *info, char **str)
{
	ctemp = va_arg(vz, wchar_t *);
	if (!ctemp)
		*str = ft_null_str(info);
	else
	{
		ctemp = ft_wstrdup(ctemp);
		ft_prec_wstr(info, ctemp);
		*str = ft_wstr_to_str(ctemp);
		free(ctemp);
	}
}
