/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 10:44:47 by pbondoer          #+#    #+#             */
/*   Updated: 2016/06/12 17:45:18 by pbondoer         ###   ########.fr       */
/*                                                                            */
	/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdio.h>

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
			image_set_pixel(mlx->image, x, y, fract_mandelbrot(x, y, mlx->viewport));
			x++;
		}
		y++;
	}
	printf("render done\n");
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}
