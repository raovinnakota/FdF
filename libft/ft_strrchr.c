/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:29:22 by rvinnako          #+#    #+#             */
/*   Updated: 2017/03/05 16:52:14 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	n;
	char	*csrc;

	csrc = (char*)s;
	n = (char)c;
	while (*csrc != '\0')
		csrc++;
	if (n == '\0')
		return (csrc);
	while (csrc != s && *csrc != n)
		csrc--;
	if (*csrc == n)
		return (csrc);
	return (NULL);
}
