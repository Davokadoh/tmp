/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 10:50:02 by pbondoer          #+#    #+#             */
/*   Updated: 2016/06/12 13:24:21 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fract_julia(int x, int y, int max)
{
	t_complex	p;
	double		tempx;
	double		tempy;

	p.cx = 3.0f;
	p.cy = 2.0f;
	p.zx = p.cx * ((double)x / WIN_WIDTH);
	p.zy = p.cy * ((double)y / WIN_HEIGHT);
	p.i = 0;
	while (p.zx * p.zx + p.zy * p.zy < 4 && p.i < max)
	{
		tempx = p.zx * p.zx - p.zy * p.zy + p.cx;
		tempy = p.zx * p.zy * 2 + p.cy;
		if (p.zx == tempx && p.zy == tempy)
		{
			p.i = max;
			break;
		}
		p.zx = tempx;
		p.zy = tempy;
		p.i++;
	}
	return (0x0000FF * (p.i / (double)max));
}
