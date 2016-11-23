/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 05:33:43 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/22 17:32:11 by lemon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include <stdlib.h>
#include <stdio.h>

int		hook_keydown(int key, t_mlx *mlx)
{
	printf("key %d\n", key);
	if (key >= K_DIGIT_1 && key <= K_DIGIT_1 + 8)
	{
		mlx->palette = &get_palettes()[key - K_DIGIT_1];
		draw(mlx);
		return (0);
	}
	if (key == K_NUM_ENTER)
	{
		mlx->smooth = 1 - mlx->smooth;
		draw(mlx);
		return (0);
	}
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	if (key == K_NUM_0)
		reset_viewport(mlx);
	if (key == K_NUM_MULT)
		mlx->viewport.max *= 2;
	if (key == K_NUM_DIV)
		mlx->viewport.max /= 2;
	if (mlx->viewport.max <= 2)
		mlx->viewport.max = 2;
	if (key == K_NUM_PLUS)
		zoom(WIN_WIDTH / 2, WIN_HEIGHT / 2, &mlx->viewport, 1 / ZOOM);
	if (key == K_NUM_MINUS)
		zoom(WIN_WIDTH / 2, WIN_HEIGHT / 2, &mlx->viewport, ZOOM);
	double w = (mlx->viewport.xmax - mlx->viewport.xmin) * mlx->viewport.zoom;
	double h = (mlx->viewport.ymax - mlx->viewport.ymin) * mlx->viewport.zoom;
	if (key == K_UP)
		mlx->viewport.offy -= h * 0.05f;
	if (key == K_DOWN)
		mlx->viewport.offy += h * 0.05f;
	if (key == K_LEFT)
		mlx->viewport.offx -= w * 0.05f;
	if (key == K_RIGHT)
		mlx->viewport.offx += w * 0.05f;
	if (key == K_L)
		mlx->mouselock = 1 - mlx->mouselock;
	render(mlx);
	return (0);
}
