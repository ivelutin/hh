/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmask.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 04:49:22 by ivelutin          #+#    #+#             */
/*   Updated: 2017/12/01 04:50:50 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	bitmask_2bytes(wchar_t chr, char *str)
{
	str[0] = (unsigned char)((chr >> 6) | 0xC0);
	str[1] = (unsigned char)((chr & 0x3F) | 0x80);
}

void	bitmask_3bytes(wchar_t chr, char *str)
{
	str[0] = (unsigned char)(((chr >> 12)) | 0xE0);
	str[1] = (unsigned char)(((chr >> 6) & 0x3F) | 0x80);
	str[2] = (unsigned char)((chr & 0x3F) | 0x80);
}

void	bitmask_4bytes(wchar_t chr, char *str)
{
	str[0] = (unsigned char)(((chr >> 18)) | 0xF0);
	str[1] = (unsigned char)(((chr >> 12) & 0x3F) | 0x80);
	str[2] = (unsigned char)(((chr >> 6) & 0x3F) | 0x80);
	str[3] = (unsigned char)((chr & 0x3F) | 0x80);
}
