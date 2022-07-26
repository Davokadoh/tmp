/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 14:43:24 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/23 02:42:55 by pbondoer         ###   ########.fr       */
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

t_color		linear_color(double i, int max, t_palette *p)
{
	double		index;
	double		adjust;
	int			c;

	if (p->cycle)
		index = fmod(i, p->cycle - 1) / (p->cycle - 1);
	else
		index = i / max;
	c = p->count - 1;
	adjust = fmod(index, 1.0f / c) * c;
	return (clerp(
		(t_color)(p->colors[(int)(index * c) + 1]),
		(t_color)(p->colors[(int)(index * c)]),
		(int)(adjust + 1) - adjust));
}

t_color		smooth_color(t_pixel p, int max, t_palette *pal)
{
	double i;
	double zn;
	double nu;

	zn = log(p.c.r * p.c.r + p.c.i * p.c.i) / 2.0f;
	nu = log(zn / log(2)) / log(2);
	i = p.i + 1 - nu;
	if (i < 0)
		i = 0;
	return (linear_color(i, max, pal));
}

//int			get_color(t_pixel p, t_mlx *mlx)
//{
//	if (p.i >= mlx->viewport.max)
//		return (0x000000);
//	if (mlx->smooth)
//		return (smooth_color(p, mlx->viewport.max, mlx->palette).value);
//	return (linear_color((double)p.i, mlx->viewport.max, mlx->palette).value);
//}




t_color HSVtoRGB(int h, int s, int v)
{
	t_color color;
	int r, g, b;
	float C = s/100*v/100;
	float X = C*(1-fabs(fmod(h/60.0, 2)-1));
	float m = v/100-C;

	if(h >= 0 && h < 60){
        r = C,g = X,b = 0;
    }
    else if(h >= 60 && h < 120){
        r = X,g = C,b = 0;
    }
    else if(h >= 120 && h < 180){
        r = 0,g = C,b = X;
    }
    else if(h >= 180 && h < 240){
        r = 0,g = X,b = C;
    }
    else if(h >= 240 && h < 300){
        r = X,g = 0,b = C;
    }
    else{
        r = C,g = 0,b = X;
    }
    color.rgba.r = (r+m)*255;
	color.rgba.g = (g+m)*255;
    color.rgba.b = (b+m)*255;
	color.rgba.a = 0;
	return (color);
}

int			get_color(t_pixel p, t_mlx *mlx)
{
	//if (p.i >= mlx->viewport.max)
	//	return (0);
	//return (HSVtoRGB(p.i % 255, 255, 255).value);
	return (HSVtoRGB(p.i * p.i % 256, 255, 255 * (p.i < mlx->viewport.max)).value);

}
