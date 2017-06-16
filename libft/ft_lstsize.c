/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 20:14:18 by rvinnako          #+#    #+#             */
/*   Updated: 2017/03/10 18:28:00 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *begin_list)
{
	int			count;
	t_list		*list;

	count = 0;
	list = begin_list;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}
