/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:08:42 by ivelutin          #+#    #+#             */
/*   Updated: 2018/01/18 12:33:18 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_imaxtoa(intmax_t value)
{
	uintmax_t	i;
	intmax_t	size;
	char		*ret;

	ret = 1;
	i = (value < 0) ? -value : value;
	size = 1 + (value < 0);
	while ((i /= 10))
		size++;
	if (ret)
	{
		ret = (char *)malloc(sizeof(char) * (size + 1));
		ret[size] = '\0';
		i = (value < 0) ? -value : value;
		ret[--size] = "0123456789"[i % 10];
	}
	while ((i /= 10))
		ret[--size] = "0123456789"[i % 10];
	if (value < 0)
		ret[--size] = '-';
	return (ret);
}
