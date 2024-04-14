/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_m_j.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:02:11 by clira-ne          #+#    #+#             */
/*   Updated: 2024/04/11 18:06:09 by clira-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_mandelbrot_fractol(t_graphic *g, int x, int y)
{
	double	x_real;
	double	y_imaginary;
	double	c_real;
	double	c_imaginary;
	double	temp;

	g->iteration = 0;
	x_real = ft_map(x, WIDTH, g->max_min_x);
	y_imaginary = ft_map(y, HEIGHT, g->max_min_y);
	c_real = ft_map(x, WIDTH, g->max_min_x);
	c_imaginary = ft_map(y, HEIGHT, g->max_min_y);
	while (g->iteration < g->infinity)
	{
		temp = (x_real * x_real - y_imaginary * y_imaginary) + c_real;
		y_imaginary = 2.0f * x_real * y_imaginary + c_imaginary;
		x_real = temp;
		if ((x_real * x_real + y_imaginary * y_imaginary) > 4.0f)
			break ;
		g->iteration++;
	}
	return (g->iteration);
}

int	ft_julia_fractol(t_graphic *g, int x, int y, double num_complex[2])
{
	double	x_real;
	double	y_imaginary;
	double	temp;

	g->iteration = 0;
	x_real = ft_map(x, WIDTH, g->max_min_x);
	y_imaginary = ft_map(y, HEIGHT, g->max_min_y);
	while (g->iteration < g->infinity)
	{
		temp = (x_real * x_real - y_imaginary * y_imaginary) + num_complex[0];
		y_imaginary = 2.0f * x_real * y_imaginary + num_complex[1];
		x_real = temp;
		if ((x_real * x_real + y_imaginary * y_imaginary) > 4.0f)
			break ;
		g->iteration++;
	}
	return (g->iteration);
}
