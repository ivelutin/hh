/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:15:13 by ivelutin          #+#    #+#             */
/*   Updated: 2017/07/06 15:24:18 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putwchar(wchar_t ws)
{
	if (ws <= 127)
		ft_putchar(ws);
	else if (ws < 2048)
		write(2, &ws, 1);
	else if (ws < 65536)
		write(3, &ws, 1);
	else if (ws < 1114112)
		write(4, &ws, 1);
}
