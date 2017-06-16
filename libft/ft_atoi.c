/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:51:03 by rvinnako          #+#    #+#             */
/*   Updated: 2017/03/06 13:48:10 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int					index;
	unsigned long long	result;
	int					sign;

	index = 0;
	result = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\f' || *str == '\r' || *str == '\v')
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0')
		str++;
	while (str[index] != '\0' && ('0' <= str[index] && '9' >= str[index]))
	{
		result = result * 10 + (str[index] - '0');
		index++;
	}
	if (index > 19)
		return ((sign == 1) ? -1 : 0);
	return (sign * (int)result);
}
