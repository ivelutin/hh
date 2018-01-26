/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:46:05 by ivelutin          #+#    #+#             */
/*   Updated: 2017/11/30 21:04:11 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_vec_append(t_vec *vec, char *newdata)
{
	size_t nd_len;

	nd_len = ft_strlen(newdata);
	if (vec->cap < vec->len + nd_len)
		ft_vec_resize(vec, vec->len + nd_len);
	ft_memcpy(vec->data + vec->len, newdata, nd_len);
	vec->len += nd_len;
}

void	ft_vec_resize(t_vec *vec, size_t min)
{
	size_t	mllc_size;

	if (!(vec->data))
		ft_vec_init(vec, min);
	mllc_size = vec->cap;
	while (mllc_size < min)
		mllc_size *= 2;
	vec->data = (char *)ft_realloc(vec->data, vec->len, mllc_size);
	vec->cap = mllc_size;
}

void	ft_vec_nappend(t_vec *vec, char *newdata, size_t n)
{
	size_t nd_len;

	nd_len = n;
	if (vec->cap < vec->len + nd_len)
		ft_vec_resize(vec, vec->len + nd_len);
	ft_memcpy(vec->data + vec->len, newdata, nd_len);
	vec->len += nd_len;
}

void	ft_vec_free(t_vec *vec)
{
	if (vec->data && vec->cap > 0)
	{
		free(vec->data);
		vec->data = NULL;
	}
}
