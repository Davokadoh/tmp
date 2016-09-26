/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 10:33:04 by pbondoer          #+#    #+#             */
/*   Updated: 2016/06/12 10:38:16 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*get_name(char *fract)
{
	if (ft_strcmp(fract, "mandelbrot") == 0)
		return ("Mandelbrot");
	else if (ft_strcmp(fract, "julia") == 0)
		return ("Julia");
	return ("invalid");
}
