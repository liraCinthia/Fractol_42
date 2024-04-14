/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:06:53 by clira-ne          #+#    #+#             */
/*   Updated: 2024/04/11 18:10:18 by clira-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_fractol(t_data *img, int iteration)
{
	int	x;
	int	y;

	y = 0;
	img->g.max_min_x[0] = -2.f * img->g.zoom;
	img->g.max_min_x[1] = 2.0f * img->g.zoom;
	img->g.max_min_y[0] = -2.0f * img->g.zoom;
	img->g.max_min_y[1] = 2.0f * img->g.zoom;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (img->type == 'j')
				iteration = ft_julia_fractol(&img->g, x, y, img->num_complex);
			else
				iteration = ft_mandelbrot_fractol(&img->g, x, y);
			if (iteration == 100)
				img->addr[y * WIDTH + x] = 0x00000000;
			else
				img->addr[y * WIDTH + x] = ft_color(((float)iteration) / 100.0);
			x++;
		}
		y++;
	}
}
