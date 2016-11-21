/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 14:43:24 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/21 14:34:20 by lemon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "math.h"
#include <stdio.h>

t_color		clerp(t_color c1, t_color c2, float p)
{
	if (c1.value == c2.value)
		return (c1);
	c1.rgba.r = ft_lerpi(c1.rgba.r, c2.rgba.r, p);
	c1.rgba.g = ft_lerpi(c1.rgba.g, c2.rgba.g, p);
	c1.rgba.b = ft_lerpi(c1.rgba.b, c2.rgba.b, p);
	c1.rgba.a = 0x00;
	return (c1);
}
t_color		linear_color(double iter, int max)
{
	t_color c;

	c.rgba.r = (char)(iter / max * 255);
	c.rgba.g = (char)(iter / max * 127);
	c.rgba.b = 0;
	c.rgba.a = 0x00;
	return (c);
}
t_color		smooth_color(t_pixel p, int max)
{
	static double log2 = log(2);
	double i;
	double zn;
	double nu;

	zn = log(p.c.r * p.c.r + p.c.i * p.c.i) / 2.0f;
	nu = log(zn / log2) / log2;
	i = p.i + 1 - nu;
	return (linear_color(i, max));
}
int			get_color(t_pixel p, t_mlx *mlx)
{
	if (p.i >= mlx->viewport.max)
		return (0x000000);
	if (mlx->smooth)
		return (smooth_color(p, mlx->viewport.max).value);
	return (linear_color((double)p.i, mlx->viewport.max).value);
}
