/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:05:04 by rvinnako          #+#    #+#             */
/*   Updated: 2017/03/05 17:55:04 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	int			len;
	const char	*limit;

	limit = big + n;
	if (*little == '\0')
		return ((char*)big);
	while (*big && big < limit)
	{
		len = 0;
		while (*big == *little && big < limit)
		{
			little++;
			big++;
			len++;
			if (!*little)
				return ((char *)(big - len));
		}
		big -= len;
		little -= len;
		big++;
	}
	return (NULL);
}
