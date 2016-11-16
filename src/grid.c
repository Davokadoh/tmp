/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 10:46:14 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/14 23:26:42 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stdio.h>

int		is_grid(int x, int y, t_viewport v)
{
	double scale;
	double real_x;
	double real_y;

	scale = ((v.xmax - v.xmin) * v.zoom) / WIN_WIDTH * (WIN_WIDTH / 10);
	real_x = ((double)x / WIN_WIDTH) * ((v.xmax - v.xmin) * v.zoom) + (v.xmin * v.zoom) + v.offx;
	real_y = ((double)y / WIN_HEIGHT) * ((v.ymax - v.ymin) * v.zoom) + (v.ymin * v.zoom) + v.offy;

	//printf("x: %f %% %f = %f\n", real_x, scale, fmod(real_x, scale));
	if (fabs(fmod(real_x, scale)) <= 0.001f)
		return (1);
	if (fabs(fmod(real_y, scale)) <= 0.001f)
		return (1);
	return (0);
}
