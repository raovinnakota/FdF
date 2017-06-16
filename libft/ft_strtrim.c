/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:09:16 by rvinnako          #+#    #+#             */
/*   Updated: 2017/03/07 16:12:01 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *src)
{
	char	*dst;
	size_t	len;
	size_t	i;

	dst = (char *)malloc(sizeof(char));
	if (dst == NULL)
		return (0);
	if (!src)
		return (0);
	len = 0;
	i = -1;
	while (*src && src != 0 && ((*src == ' ' || *src == '\n' || *src == '\t')))
		src++;
	while (src[len] && src)
		len++;
	while ((src[len - 1] == '\n' || src[len - 1] == '\t'
			|| src[len - 1] == ' ') && len > 0)
		len--;
	dst = (char*)malloc(sizeof(char) * (len + 1));
	while (++i < len)
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
