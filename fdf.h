/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:18:31 by rvinnako          #+#    #+#             */
/*   Updated: 2017/06/30 14:14:17 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

typedef struct		s_line
{
	int				x_start;
	int				y_start;
	int				x_end;
	int				y_end;
}					t_line;


#endif
