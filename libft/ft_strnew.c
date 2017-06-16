/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:29:55 by rvinnako          #+#    #+#             */
/*   Updated: 2017/03/06 15:53:24 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;
	char *str2;

	size++;
	str = (char *)malloc(sizeof(*str) * size);
	str2 = str;
	if (!str)
		return (NULL);
	while (size > 0)
	{
		*str = 0;
		str++;
		size--;
	}
	return (str2);
}
