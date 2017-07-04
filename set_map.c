/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 16:00:11 by rvinnako          #+#    #+#             */
/*   Updated: 2017/07/03 17:45:10 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**get_row(char *str)
{
	char **row;

	row = ft_split(str, ' ');
	return (row);
}

void 	set_line(int **int_arr, char **row)
{
	int		c_count;
	int		i_count;

	c_count = 0;
	i_count = 0;
	while (row[c_count])
	{
		*int_arr[i_count] = ft_atoi(row[c_count]);
		i_count++;
		c_count++;
	}
}

int		get_area(char **line)
{
	int height;
	int width;

	height = 0;
	width = ft_strlen(line[height]);
	while (line[height])
		height++;
	return (width * height);
}

int		**get_int_map(char **line)
{
	int		i;
	int		**ret;
	char	**temp;

	i = 0;
	ret = (int**)malloc(sizeof(int*) * get_area(line));
	temp = get_row(line[i]);
}
