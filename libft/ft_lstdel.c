/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:52:03 by rvinnako          #+#    #+#             */
/*   Updated: 2017/03/10 15:58:29 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!*alst || !alst)
		return ;
	while (*alst)
	{
		if (del)
			del((*alst)->content, (*alst)->content_size);
		tmp = (*alst)->next;
		free(*alst);
		*alst = NULL;
		*alst = tmp;
	}
}
