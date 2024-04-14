/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:11:51 by clira-ne          #+#    #+#             */
/*   Updated: 2024/04/14 09:55:09 by clira-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_close_win(t_data *img)
{
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	exit(EXIT_SUCCESS);
}

int	ft_key_escape(int key, t_data *img)
{
	if (key == ESC)
	{
		mlx_destroy_image(img->mlx, img->img);
		mlx_destroy_window(img->mlx, img->mlx_win);
		mlx_destroy_display(img->mlx);
		free(img->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	ft_scroll_zoom(int key, int x, int y, t_data *img)
{
	if (key == M_UP)
		img->g.zoom *= 0.94;
	else if (key == M_DOWN)
		img->g.zoom *= 1.1;
	img->mouse_x = x;
	img->mouse_y = y;
	ft_fractol(img, 0);
	ft_refresh_window(img);
	return (0);
}
