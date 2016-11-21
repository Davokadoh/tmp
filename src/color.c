/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 14:43:24 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/21 15:26:31 by lemon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "math.h"

t_color		clerp(t_color c1, t_color c2, double p)
{
	t_color c;

	if (c1.value == c2.value)
		return (c1);
	c.rgba.r = (char)ft_lerpi((int)c1.rgba.r, (int)c2.rgba.r, p);
	c.rgba.g = (char)ft_lerpi((int)c1.rgba.g, (int)c2.rgba.g, p);
	c.rgba.b = (char)ft_lerpi((int)c1.rgba.b, (int)c2.rgba.b, p);
	c.rgba.a = (char)0x00;
	return (c);
}
t_color		linear_color(double iter, int max)
{
	t_color c1;
	t_color c2;

	c1.value = 0x00000000;
	c2.value = 0xFFFFFFFF;
	return (clerp(c1, c2, iter / max));
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
	if (i < 0)
		i = 0;
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
