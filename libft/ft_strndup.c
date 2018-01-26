/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:09:09 by ivelutin          #+#    #+#             */
/*   Updated: 2018/01/25 17:18:32 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t len)
{
	char	*dst;
	char	*cdst;

	if (!(dst = ft_strnew(len + 1)))
		return NULL;
	cdst = NULL;
	if (dst)
	{
		cdst = dst;
		len++;
		while (--len > 0)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (cdst);
}
