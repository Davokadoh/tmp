/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 10:44:47 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/19 15:14:30 by pbondoer         ###   ########.fr       */
/*                                                                            */
	/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdio.h>

void		request_render(t_mlx *mlx)
{
	mlx->render = 1;
}

void		render(t_mlx *mlx)
{
	int x;
	int y;

	clear_image(mlx->image);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			//if (is_grid(x, y, mlx->viewport))
			//	image_set_pixel(mlx->image, x, y, 0x000000);
			//else
			int c = mandelbrot_fractal(x, y, mlx->viewport);
			image_set_pixel(mlx->image, x, y, c);
			x++;
		}
		y++;
	}
	printf("render done at %d iterations\n", mlx->viewport.max);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}
