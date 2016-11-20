/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:18:53 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/20 00:54:37 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		viewport_fit(t_viewport *v)
{
	double w;
	double h;
	
	w = v->xmax - v->xmin;
	h = v->ymax - v->ymin;
	if (w / h >= (float)WIN_WIDTH / WIN_HEIGHT)
	{
		v->ymin = -(w * WIN_HEIGHT / WIN_WIDTH / 2);
		v->ymax = (w * WIN_HEIGHT / WIN_WIDTH / 2);
	} else {
		v->xmin = -0.5 - (h * WIN_WIDTH / WIN_HEIGHT / 2);
		v->xmax = -0.5 + (h * WIN_WIDTH / WIN_HEIGHT / 2);
	}
}

t_complex	screen_to_complex(int x, int y, t_viewport *v)
{
	t_complex	p;
	double		z;

	z = v->zoom;
	p.cr = (((double)x / WIN_WIDTH) * (v->xmax - v->xmin)) * z + v->xmin + v->offx;
	p.ci = (((double)y / WIN_HEIGHT) * (v->ymax - v->ymin)) * z + v->ymin + v->offy;
	p.zr = p.cr;
	p.zi = p.ci;
	p.i = 0;
	return (p);
}
