/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 10:50:02 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/20 00:56:30 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <math.h>

int		mandelbrot_fractal(int x, int y, t_viewport v)
{
	t_complex	p;
	double		tempr;
	double		tempi;
	double		tp;

	p = screen_to_complex(x, y, &v);

	if ((p.cr + 1) * (p.cr + 1) + (p.ci * p.ci) < 1.0f / 16.0f)
		return (0x0);
	tp = sqrt((p.cr - 0.25f) * (p.cr - 0.25f) + (p.ci * p.ci));
	if (p.cr < tp - 2 * tp * tp + 0.25f)
		return (0x0);

	while (p.zr * p.zr + p.zi * p.zi < (1 << 8) && p.i < v.max)
	{
		tempr = p.zr * p.zr - p.zi * p.zi + p.cr;
		tempi = p.zr * p.zi * 2 + p.ci;
		if (p.zr == tempr && p.zi == tempi)
		{
			ft_putendl("periodicity checking exit");
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

void	mandelbrot_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -1.0f;
	v->ymax = 1.0f;
}
