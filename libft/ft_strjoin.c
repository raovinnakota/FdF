/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:17:13 by rvinnako          #+#    #+#             */
/*   Updated: 2017/03/07 14:31:20 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen((char *)(s1));
	len2 = ft_strlen((char *)(s2));
	str = ft_strnew(len1 + len2);
	if (str == NULL)
		return (0);
	str = ft_strncpy(str, (char *)s1, len1);
	str = ft_strcat(str, s2);
	return (str);
}
