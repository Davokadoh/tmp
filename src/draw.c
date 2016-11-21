/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 10:44:47 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/21 14:31:55 by lemon            ###   ########.fr       */
/*                                                                            */
	/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void		render(t_mlx *mlx)
{
	int x;
	int y;
	int color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			color = get_color(mlx->fractal->pixel(x, y, &mlx->viewport), mlx);
			image_set_pixel(mlx->image, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}
