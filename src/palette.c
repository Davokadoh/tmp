/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemon <pierre@bondoer.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:17:45 by lemon             #+#    #+#             */
/*   Updated: 2016/11/22 00:58:59 by lemon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stddef.h>

#include <stdio.h>
/*
** Defines our palette
**   count -> total amount of color entries
**   cycle -> 0 = linear, n = 0-n iterations
*/
t_palette	*get_palettes()
{
	static	t_palette array[10] = {
		(t_palette){2, 0, {0x000000, 0xFF7F00}},
		(t_palette){7, 20, {0xFF0000, 0xFFFF00, 0x00FF00, 0x00FFFF,
			0x0000FF, 0xFF00FF, 0xFF0000}},
		(t_palette){3, 0, {0x0000FF, 0xFFFFFF, 0xFF0000}},
		(t_palette){0, 0, {0}}
	};

	return (array);
}
