/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 10:33:04 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/14 23:55:11 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

t_fractal	**get_fractals()
{
	static t_fractal *array[2];

	array[0] = &(t_fractal){"mandelbrot", mandelbrot_viewport,
		mandelbrot_fractal};
	array[1] = (t_fractal *)NULL;
	return (array);
}

t_fractal	*fractal_match(char *str)
{
	t_fractal **f;
	int i;

	f = get_fractals();
	i = 0;
	while (f[i] != NULL)
	{
		if (ft_strcmp(f[i]->name, str) == 0)
			return (f[i]);
		i++;
	}
	return (NULL);
}

char		*get_name(char *fract)
{
	t_fractal *f;

	if ((f = fractal_match(fract)) == NULL)
		return ("invalid");
	return (f->name);
}
