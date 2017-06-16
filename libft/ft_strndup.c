/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 12:13:20 by rvinnako          #+#    #+#             */
/*   Updated: 2017/06/15 13:45:46 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t size)
{
	char	*ret;

	ret = ft_strnew(size);
	ft_bzero(ret, size);
	ft_strncpy(ret, (char*)str, size);
	return (ret);
}
