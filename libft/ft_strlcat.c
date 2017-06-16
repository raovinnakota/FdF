/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:58:27 by rvinnako          #+#    #+#             */
/*   Updated: 2017/03/03 17:37:41 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t length;
	size_t origin;

	length = 0;
	origin = size + ft_strlen((char*)src);
	while (*dst && size > 0)
	{
		length++;
		size--;
		dst++;
	}
	if (size < 1)
		return (origin);
	size--;
	while (*src && size > 0)
	{
		*dst++ = *src++;
		length++;
		size--;
	}
	while (*src++)
		length++;
	*dst = '\0';
	return (length);
}
