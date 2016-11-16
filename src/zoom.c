/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:39:58 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/14 20:27:06 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

#include <stdio.h>

void		zoom(int x, int y, t_viewport *v, double z)
{
	(void)x; (void)y; (void)v; (void)z;

	double w = (v->xmax - v->xmin) * (v->zoom);
	double h = (v->ymax - v->ymin) * (v->zoom);
	double nw = ((v->xmax - v->xmin) * (v->zoom * z));
	double nh = ((v->ymax - v->ymin) * (v->zoom * z));
	
	double dx = ((double)x / WIN_WIDTH) * (nw - w);
	double dy = ((double)y / WIN_HEIGHT) * (nh - h);

	v->zoom *= z;
	v->offx -= dx;
	v->offy -= dy;

	printf("new zoom: %f\n", v->zoom);
}
