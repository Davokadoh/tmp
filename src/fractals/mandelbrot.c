/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 10:50:02 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/21 14:19:55 by lemon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <math.h>

t_pixel		mandelbrot_pixel(int x, int y, t_viewport *v)
{
	t_pixel		p;
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	double		tp;
	int			i;

	z = screen_to_complex(x, y, v);
	c = screen_to_complex(x, y, v);
	i = 0;
	if ((c.r + 1) * (c.r + 1) + (c.i * c.i) < 1.0f / 16.0f)
		i = v->max;
	tp = sqrt((c.r - 0.25f) * (c.r - 0.25f) + (c.i * c.i));
	if (c.r < tp - 2 * tp * tp + 0.25f)
		i = v->max;
	while (z.r * z.r + z.i * z.i < (1 << 8) && i < v->max)
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = z.r * z.i * 2 + c.i;
		if (z.r == temp.r && z.i == temp.i)
		{
			i = v->max;
			break ;
		}
		z.r = temp.r;
		z.i = temp.i;
		i++;
	}
	p.c = z;
	p.i = i;
	return (p);
}

void	mandelbrot_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -1.0f;
	v->ymax = 1.0f;
	v->offx = -0.5f;
}
