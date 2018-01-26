/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:08:32 by ivelutin          #+#    #+#             */
/*   Updated: 2017/12/15 06:35:04 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_findchr(const char *s, int c)
{
	int				i;
	unsigned char	a;

	a = (unsigned char)c;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == a)
			return (i);
	}
	if (s[i] == a)
		return (ft_strlen(s) + 1);
	return (0);
}
