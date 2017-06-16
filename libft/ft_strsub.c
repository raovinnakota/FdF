/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 13:57:48 by rvinnako          #+#    #+#             */
/*   Updated: 2017/03/07 14:15:24 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (!s)
		return (0);
	i = 0;
	str = ft_strnew(len);
	if (str == NULL)
		return (0);
	while (len > 0)
	{
		str[i] = s[start];
		i++;
		start++;
		len--;
	}
	return (str);
}
