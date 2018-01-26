/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:09:16 by ivelutin          #+#    #+#             */
/*   Updated: 2018/01/18 12:25:10 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uimaxtoa_base(uintmax_t value, int8_t base, const char *str)
{
	uintmax_t	i;
	size_t		size;
	char		*ret;

	i = value;
	size = 1;
	ret = 1;
	while ((i /= base))
		size++;
	if (ret)
	{
		ret = (char *)malloc(sizeof(char) * (size + 1));
		ret[size] = '\0';
		i = value;
		ret[--size] = str[i % base];
	}
	while ((i /= base))
		ret[--size] = str[i % base];
	return (ret);
}
