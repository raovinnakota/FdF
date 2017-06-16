/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:55:11 by rvinnako          #+#    #+#             */
/*   Updated: 2017/03/06 15:03:53 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*source;
	unsigned char		ch;

	dest = (unsigned char *)(dst);
	source = (const unsigned char *)(src);
	ch = (unsigned char)(c);
	while (n > 0)
	{
		*dest = *source;
		if (*source == ch)
		{
			dest++;
			return ((void *)dest);
		}
		dest++;
		source++;
		n--;
	}
	return (0);
}
