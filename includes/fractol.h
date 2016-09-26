/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 08:35:18 by pbondoer          #+#    #+#             */
/*   Updated: 2016/06/12 17:44:09 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

typedef struct		s_rgba
{
	char		b;
	char		g;
	char		r;
	char		a;
}					t_rgba;
typedef union		u_color
{
	int			value;
	t_rgba		rgba;
}					t_color;
typedef struct		s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}					t_mouse;
typedef struct		s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}					t_image;
typedef struct		s_viewport
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	int			max;
}					t_viewport;
typedef struct		s_mlx
{
	void		*mlx;
	void		*window;
	t_image		*image;
	t_mouse		mouse;
	t_viewport	viewport;
}					t_mlx;
typedef struct		s_complex
{
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	int			i;
}					t_complex;

t_mlx				*mlxdel(t_mlx *mlx);
t_mlx				*init(char *title);
void				render(t_mlx *mlx);
int					hook_mousedown(int button, int x, int y, t_mlx *mlx);
int					hook_mouseup(int button, int x, int y, t_mlx *mlx);
int					hook_mousemove(int x, int y, t_mlx *mlx);
int					hook_keydown(int key, t_mlx *mlx);
int					hook_expose(t_mlx *mlx);
t_image				*del_image(t_mlx *mlx, t_image *img);
t_image				*new_image(t_mlx *mlx);
void				clear_image(t_image *img);
void				image_set_pixel(t_image *image, int x, int y, int color);
char				*get_name(char *fract);
int					fract_mandelbrot(int x, int y, t_viewport v);
int					fract_julia(int x, int y, int max);
t_color				get_color(double iter);
int					smooth_color(t_complex p, int max);
void				zoom(int x, int y, t_viewport *v, double z);
#endif
