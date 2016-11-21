/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 08:35:18 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/21 14:31:29 by lemon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define GRIDSIZE 64
# define ZOOM 1.1f

typedef struct		s_hsv
{
	int			h;
	int			s;
	int			v;
}					t_hsv;
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
	double		zoom;
	double		offx;
	double		offy;
	int			max;
}					t_viewport;
typedef struct		s_complex
{
	double		r;
	double		i;
}					t_complex;
typedef struct		s_pixel
{
	t_complex	c;
	int			i;
}					t_pixel;
typedef struct		s_fractal
{
	char		*name;
	void		(*viewport)(t_viewport *);
	t_pixel		(*pixel)(int, int, t_viewport *);
}					t_fractal;
typedef struct		s_mlx
{
	void		*mlx;
	void		*window;
	t_fractal	*fractal;
	t_pixel		**data; // raw fractal data as 2d array
	t_image		*image; // this is what we're displaying on screen
	t_mouse		mouse;
	t_viewport	viewport;
	int			smooth;
}					t_mlx;

t_mlx				*mlxdel(t_mlx *mlx);
t_mlx				*init(t_fractal *f);
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
t_fractal			*fractal_match(char *str);
t_pixel				mandelbrot_pixel(int x, int y, t_viewport *v);
void				mandelbrot_viewport(t_viewport *v);
int					get_color(t_pixel p, t_mlx *mlx);
void				zoom(int x, int y, t_viewport *v, double z);
int					is_grid(int x, int y, t_viewport v);
void				viewport_fit(t_viewport *v);
t_complex			screen_to_complex(int x, int y, t_viewport *v);
#endif
