/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:45:44 by ivelutin          #+#    #+#             */
/*   Updated: 2017/12/03 22:37:24 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void				ft_prec_nums(t_info *info, char **str)
{
	char *new;
	char extra;
	char *orig;

	orig = *str;
	extra = 0;
	if (ft_pnum(extra, &new, info, str))
		return ;
	free(orig);
	*str = new;
}

void				ft_prec_handle(t_info *info, char **str)
{
	if (info->prec == -1)
		return ;
	if (ft_strlen(*str) <= (size_t)info->prec)
		return ;
	(*str)[info->prec] = '\0';
}

void				ft_right_just(t_info *info, char **str, char *new)
{
	char extra;

	extra = 0;
	if (info->flags & ZER)
		ft_rjif(extra, new, info, str);
	else
		ft_rjelse(new, info, str);
	ft_strcpy(new + info->width - ft_strlen(*str) + !!extra, *str + !!extra);
}

static inline void	ft_left_just(t_info *info, char **str, char *new)
{
	ft_strcpy(new, *str);
	ft_memset(new + ft_strlen(*str), ' ', info->width - ft_strlen(*str));
}

void				ft_pad_handle(t_info *info, char **str)
{
	char	*new;

	if (info->width == 0 || ft_strlen(*str) >= (size_t)info->width)
		return ;
	new = ft_strnew(info->width);
	if (info->flags & LFT)
		ft_left_just(info, str, new);
	else
		ft_right_just(info, str, new);
	free(*str);
	*str = new;
	return ;
}
