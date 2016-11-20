/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 08:28:17 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/19 18:11:46 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include "mlx.h"

int		hook_expose(t_mlx *mlx)
{
	render(mlx);
	return (0);
}

int		die(char *reason)
{
	ft_putendl(reason);
	return (1);
}

int		hook_loop(t_mlx *mlx)
{
	if (!mlx->render)
		return (0);
	ft_putendl("hi im loop");
	mlx->render = 0;
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc < 2)
		return (die("error: not enough arguments"));
	if ((mlx = init(ft_strjoin("Fract'ol - ", get_name(argv[1])))) == NULL)
		return (die("error: mlx couldn't init"));
	mandelbrot_viewport(&mlx->viewport);
	viewport_fit(&mlx->viewport);
	mlx->viewport.max = 64;
	mlx->viewport.zoom = 1.0f;
	render(mlx);
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_expose_hook(mlx->window, hook_expose, mlx);
	mlx_hook(mlx->window, 4, 1L << 2, hook_mousedown, mlx);
	mlx_hook(mlx->window, 5, 1L << 3, hook_mouseup, mlx);
	mlx_hook(mlx->window, 6, 1L << 6, hook_mousemove, mlx);
	//mlx_hook(mlx->window, 33, 0, hook_clientmessage, mlx);
	mlx_loop_hook(mlx->mlx, hook_loop, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
