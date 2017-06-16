/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:03:09 by rvinnako          #+#    #+#             */
/*   Updated: 2017/02/27 15:16:27 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*s2;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	s2 = (char*)malloc(sizeof(*s2) * (len + 1));
	if (s2 == NULL)
		return (0);
	else
	{
		while (i < len)
		{
			s2[i] = s1[i];
			i++;
		}
	}
	s2[i] = '\0';
	return (s2);
}
