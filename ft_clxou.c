/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clxou.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 23:10:48 by ivelutin          #+#    #+#             */
/*   Updated: 2017/12/03 23:27:47 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_clhand_alt(t_info *info, char **str, char **new)
{
	if (info->spec == 'b' && ft_strcmp("0", *str) &&
										ft_strcmp("\0", *str))
		ft_insrt_to_str(new, "0b");
	else if ((info->spec == 'x' || info->spec == 'X')
			&& ft_strcmp("0", *str) && ft_strcmp("\0", *str))
		ft_insrt_to_str(new, "0x");
	else if (info->spec == 'o' && **str != '0')
		ft_insrt_to_str(new, "0");
}

void	ft_clhand_xou(t_info *info, char **str)
{
	if (info->flags & ZER && info->spec == 'p')
	{
		info->width = MAX(info->width - 2, 0);
		ft_pad_handle(info, str);
	}
	else if (info->flags & ZER && info->flags & HTG &&
		((info->spec == 'x') || info->spec == 'b'))
	{
		info->width = MAX(info->width - 2, 0);
		ft_pad_handle(info, str);
	}
	ft_handle_alt(info, str);
	if (!(info->flags & ZER && info->flags & HTG &&
	(info->spec == 'x' || info->spec == 'p' || info->spec == 'b')))
		ft_pad_handle(info, str);
}
