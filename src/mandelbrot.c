/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 10:50:02 by pbondoer          #+#    #+#             */
/*   Updated: 2016/06/18 13:16:59 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fract_mandelbrot(int x, int y, t_viewport v)
{
	t_complex	p;
	double		tempr;
	double		tempi;

	p.cr = ((double)x / WIN_WIDTH) * (v.xmax - v.xmin) + v.xmin;
	p.ci = ((double)y / WIN_HEIGHT) * (v.ymax - v.ymin) + v.ymin;
	p.zr = 0.0f;
	p.zi = 0.0f;
	p.i = 0;
	while (p.zr * p.zr + p.zi * p.zi < 4 && p.i < v.max)
	{
		tempr = p.zr * p.zr - p.zi * p.zi + p.cr;
		tempi = p.zr * p.zi * 2 + p.ci;
		if (p.zr == tempr && p.zi == tempi)
		{
			p.i = v.max;
			break ;
		}
		p.zr = tempr;
		p.zi = tempi;
		p.i++;
	}
	//return (get_color(p.i).value);
	return (smooth_color(p, v.max));
}
