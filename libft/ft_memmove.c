/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 18:10:49 by rvinnako          #+#    #+#             */
/*   Updated: 2017/03/05 18:43:24 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*memsrc;
	unsigned char		*memdst;
	unsigned char		*final;

	memsrc = (const unsigned char*)src;
	memdst = (unsigned char*)dst;
	final = memdst;
	if (memdst > memsrc)
	{
		memsrc = memsrc + len - 1;
		memdst = memdst + len - 1;
		while (len-- > 0)
			*memdst-- = *memsrc--;
	}
	else
	{
		while (len-- > 0)
			*memdst++ = *memsrc++;
	}
	return (final);
}
