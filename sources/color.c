/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:16:13 by clira-ne          #+#    #+#             */
/*   Updated: 2024/04/12 18:10:22 by clira-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_color_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_color(float iteration)
{
	int		r;
	int		g;
	int		b;
	float	rgb[3];

	rgb[0] = 0.6 * pow(iteration, 2) * 255;
	rgb[1] = 0.2 * pow(iteration, 3) * 255;
	rgb[2] = 0.9 * pow(iteration, 2) * 255;
	r = 255.999 * rgb[0];
	g = 255.999 * rgb[1];
	b = 255.999 * rgb[2];
	return (ft_color_trgb(0, r, g, b));
}
