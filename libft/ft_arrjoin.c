/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 13:41:39 by rvinnako          #+#    #+#             */
/*   Updated: 2017/06/15 13:43:59 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countmem(char **arr)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (arr[i] != '\0')
	{
		len += ft_strlen(arr[i]);
		i++;
	}
	return (len);
}

char		*ft_arrjoin(char **arr)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(*str) * (ft_countmem(arr) + 1));
	while (arr[i] != '\0')
	{
		ft_strcat(str, arr[i]);
		i++;
	}
	return (str);
}
