/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 10:33:04 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/21 07:58:17 by lemon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

t_fractal	*get_fractals()
{
	static t_fractal array[2] = {
		{"mandelbrot", mandelbrot_viewport, mandelbrot_pixel},
		{NULL, NULL, NULL}
	};

	return (array);
}

t_fractal	*fractal_match(char *str)
{
	t_fractal *f;
	int i;

	f = get_fractals();
	i = 0;
	while (f[i].name != NULL)
	{
		if (ft_strcmp(f[i].name, str) == 0)
			return (&f[i]);
		i++;
	}
	return (&f[i]);
}
