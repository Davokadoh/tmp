/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 08:37:53 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/14 23:35:06 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	printf("%d --\n", button);
	if (button == 4)
	{
		//wheel down
		zoom(x, y, &mlx->viewport, 1 / ZOOM);
	}
	else if (button == 5)
	{
		zoom(x, y, &mlx->viewport, ZOOM);
	}
	(void)x;
	if (y < 0)
		return (0);
	mlx->mouse.isdown |= 1 << button;
	return (0);
}

int		hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse.isdown &= ~(1 << button);
	return (0);
}

int		hook_mousemove(int x, int y, t_mlx *mlx)
{
	mlx->mouse.lastx = mlx->mouse.x;
	mlx->mouse.lasty = mlx->mouse.y;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	if (mlx->mouse.isdown & (1 << 1) && mlx->mouse.isdown & (1 << 2))
	{
		// both buttons
	}
	else if (mlx->mouse.isdown & (1 << 1))
	{
		double w = (mlx->viewport.xmax - mlx->viewport.xmin) * mlx->viewport.zoom;
		double h = (mlx->viewport.ymax - mlx->viewport.ymin) * mlx->viewport.zoom;

		double wd = (double)(mlx->mouse.lastx - mlx->mouse.x) / WIN_WIDTH * w;
		double hd = (double)(mlx->mouse.lasty - mlx->mouse.y) / WIN_HEIGHT * h;
	
		mlx->viewport.offx += wd;
		mlx->viewport.offy += hd;
	}
	else if (mlx->mouse.isdown & (1 << 2))
	{
		//right
	}
	if (mlx->mouse.isdown)
		render(mlx);
	return (0);
}
