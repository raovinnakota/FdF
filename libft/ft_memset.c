/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:54:56 by rvinnako          #+#    #+#             */
/*   Updated: 2017/03/05 17:11:06 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char n;
	unsigned char *nsrc;

	n = (unsigned char)c;
	nsrc = (unsigned char *)b;
	while (len > 0)
	{
		len--;
		*nsrc = n;
		nsrc++;
	}
	return (b);
}
