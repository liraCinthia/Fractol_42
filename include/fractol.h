/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:26:34 by clira-ne          #+#    #+#             */
/*   Updated: 2024/04/14 10:07:35 by clira-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx-linux/mlx.h"

# define WIDTH 700
# define HEIGHT 700
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ESC 0xff1b

typedef struct s_graphic
{
	int		iteration;
	float	infinity;
	double	zoom;
	double	max_min_x[2];
	double	max_min_y[2];
}	t_graphic;

typedef struct s_data
{
	char		**argv;
	char		type;
	int			*addr;
	int			bpp;
	int			len_line;
	int			endian;
	int			mouse_x;
	int			mouse_y;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	t_graphic	g;
	double		num_complex[2];
}	t_data;

void	ft_init_img(t_data *img);
void	ft_exec_window(t_data *img);
void	ft_fractol(t_data *img, int iteration);
int		ft_isspace(int c);
int		ft_color(float iteration);
int		ft_close_win(t_data *img);
int		ft_config_env(t_data *img);
int		ft_refresh_window(t_data *img);
int		ft_key_escape(int key, t_data *img);
int		ft_color_trgb(int t, int r, int g, int b);
int		ft_mandelbrot_fractol(t_graphic *g, int x, int y);
int		ft_scroll_zoom(int key, int x, int y, t_data *img);
int		ft_julia_fractol(t_graphic *g, int x, int y, double num_complex[2]);
float	ft_atof(const char *str);
double	ft_map(double x, double in_max, double out[2]);

#endif
