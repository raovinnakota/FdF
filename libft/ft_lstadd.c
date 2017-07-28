/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:04:01 by rvinnako          #+#    #+#             */
/*   Updated: 2017/07/28 13:04:52 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd(t_list *begin_list, t_list *new)
{
	if (!begin_list || !new)
		return (0);
	new->next = begin_list;
	begin_list = new;
	return (begin_list);
}
