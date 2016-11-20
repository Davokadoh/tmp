/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 14:43:24 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/20 00:36:26 by pbondoer         ###   ########.fr       */
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

t_color		get_color(double iter, int max)
{
	t_color c;

	//TODO: proper hsv
	//c.rgba.r = (char)(iter / max * 255);
	//c.rgba.g = (char)(iter / max * 127);
	//c.rgba.b = 0;
	(void)max;
	c.rgba.r = (char)(cos(iter / 42.0f * 2.0f * M_PI) * 126 + 127);
	c.rgba.g = (char)(cos((iter / 42.0f + 0.33f) * 2.0f * M_PI) * 126 + 127);
	c.rgba.b = (char)(cos((iter / 42.0f + 0.66f) * 2.0f * M_PI) * 126 + 127);
	c.rgba.a = 0x00;
	return c;
}

int			smooth_color(t_complex p, int max)
{
	double i;
	double zn;
	double nu;
	static double log2;

	if (p.i >= max)
		return (0x000000);
	log2 = log(2);
	zn = log(p.zr * p.zr + p.zi * p.zi) / 2;
	nu = log(zn / log2) / log2;
	i = p.i + 1 - nu;
	return (get_color(i, max).value);
}
