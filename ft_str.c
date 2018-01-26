/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:45:57 by ivelutin          #+#    #+#             */
/*   Updated: 2017/12/12 14:28:41 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_null_str(t_info *info)
{
	char *temp;

	if (info->prec >= 1 || info->prec == -1)
	{
		temp = ft_strdup("(null)");
		if (info->prec > 6)
			temp[6] = '\0';
		else
			temp[(info->prec == -1) ? 6 : info->prec] = '\0';
		return (temp);
	}
	else
		{
			temp = ft_strdup("");
			return (temp);
		}
}

static	void	ft_str_type(t_info *info, t_vec *vec, va_list vz, char *str)
{
	char *ctemp;

	if (info->length == l)
	{
		ft_wstr(vec, info, vz);
		return ;
	}
	ctemp = va_arg(vz, char *);
	if (!ctemp)
		str = ft_null_str(info);
	else
		str = ft_strdup(ctemp);
	ft_prec_handle(info, &str);
	ft_pad_handle(info, &str);
	ft_vec_append(vec, str);
	free(str);
}

void	ft_str(t_vec *vec, t_info *info, va_list vz)
{
	char *str;

	str = NULL;
	ft_str_type(info, vec, vz, str);
}
