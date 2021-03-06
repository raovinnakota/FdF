/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:18:08 by rvinnako          #+#    #+#             */
/*   Updated: 2017/07/03 15:16:13 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**fill_map(int fd)
{
	int		y;
	char	**line;

	y = 0;
	line = (char**)malloc(sizeof(char*) * UINT_MAX);
	while (get_next_line(fd, &line[y]) != 0)
		y++;
	return (line);
}