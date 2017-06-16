/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:26:38 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/08 16:59:39 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	tbl_del(char **src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		free(src[i]);
		++i;
	}
	free(src);
	src = 0;
}

static int	num_block(char const *src, char c)
{
	int		i;
	int		wrd_flag;

	wrd_flag = 0;
	i = 0;
	while (*src)
	{
		if (*src == c)
			wrd_flag = 0;
		else
		{
			if (wrd_flag == 0)
				++i;
			wrd_flag = 1;
		}
		++src;
	}
	return (i);
}

static char	*each_block(char const *src, char c)
{
	int		len;
	int		i;
	char	*ret;

	len = 0;
	i = 0;
	while (src[len] != c && src[len])
		++len;
	CHK((ret = (char*)malloc(sizeof(char) * (len + 1))) == 0, 0);
	while (i < len)
	{
		ret[i] = src[i];
		++i;
	}
	ret[i] = 0;
	return (ret);
}

char		**ft_strsplit(char const *src, char c)
{
	int		num_b;
	int		i;
	char	**ret;
	int		wrd_flag;

	CHK(src == NULL, 0);
	i = 0;
	wrd_flag = 0;
	num_b = num_block(src, c);
	CHK((ret = (char**)ft_memalloc(sizeof(char*) * (num_b + 1))) == 0, 0);
	while (*src)
	{
		if (*src == c)
			wrd_flag = 0;
		else
		{
			if (wrd_flag == 0)
				CHK1((ret[i++] = each_block(src, c)) == 0, tbl_del(ret), 0);
			wrd_flag = 1;
		}
		++src;
	}
	return (ret);
}
