/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:09:25 by rvinnako          #+#    #+#             */
/*   Updated: 2017/03/05 16:34:03 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char n;

	n = (unsigned char)(c);
	while (*s != n && *s != '\0')
		s++;
	if (*s == n)
		return (char*)(s);
	return (NULL);
}
