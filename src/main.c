/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 08:28:17 by pbondoer          #+#    #+#             */
/*   Updated: 2016/06/12 16:17:11 by pbondoer         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc < 2)
		return (die("error: not enough arguments"));
	if ((mlx = init(ft_strjoin("Fract'ol - ", get_name(argv[1])))) == NULL)
		return (die("error: mlx couldn't init"));
	mlx->viewport.xmin = -2.0f;
	mlx->viewport.xmax = 1.0f;
	mlx->viewport.ymin = -1.0f;
	mlx->viewport.ymax = 1.0f;
	mlx->viewport.max = 128;
	render(mlx);
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_expose_hook(mlx->window, hook_expose, mlx);
	mlx_hook(mlx->window, 4, 0, hook_mousedown, mlx);
	mlx_hook(mlx->window, 5, 0, hook_mouseup, mlx);
	mlx_hook(mlx->window, 6, 0, hook_mousemove, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
