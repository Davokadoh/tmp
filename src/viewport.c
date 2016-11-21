/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:18:53 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/21 14:27:59 by lemon            ###   ########.fr       */
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
		v->xmin = -(h * WIN_WIDTH / WIN_HEIGHT / 2);
		v->xmax = (h * WIN_WIDTH / WIN_HEIGHT / 2);
	}
}

t_complex	screen_to_complex(int x, int y, t_viewport *v)
{
	t_complex	p;

	p.r = (((double)x / WIN_WIDTH) * (v->xmax - v->xmin)) * v->zoom
		+ v->xmin + v->offx;
	p.i = (((double)y / WIN_HEIGHT) * (v->ymax - v->ymin)) * v->zoom
		+ v->ymin + v->offy;
	return (p);
}
