/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:39:58 by pbondoer          #+#    #+#             */
/*   Updated: 2016/06/13 02:43:25 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void		zoom(int x, int y, t_viewport *v, double z)
{
	(void)x;
	(void)y;

	double		xmid;
	double		ymid;
	t_viewport	old;

	old = *v;
	xmid = v->xmin + (v->xmax - v->xmin) / 2;
	ymid = v->ymin + (v->ymax - v->ymin) / 2;
	v->xmin = ft_lerp(v->xmin, xmid, z);
	v->xmax = ft_lerp(v->xmax, xmid, z);
	v->ymin = ft_lerp(v->ymin, ymid, z);
	v->ymax = ft_lerp(v->ymax, ymid, z);
}
