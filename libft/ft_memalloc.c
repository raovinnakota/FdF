/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:49:11 by rvinnako          #+#    #+#             */
/*   Updated: 2017/03/06 14:12:10 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*tmp1;
	unsigned char	*tmp2;

	if (size == 0)
		return (0);
	tmp1 = malloc(size);
	if (tmp1 == 0)
		return (0);
	tmp2 = (unsigned char *)(tmp1);
	while (size > 0)
	{
		*tmp2 = 0;
		tmp2++;
		size--;
	}
	return (tmp1);
}
