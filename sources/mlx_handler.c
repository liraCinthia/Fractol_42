/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:58:39 by clira-ne          #+#    #+#             */
/*   Updated: 2024/04/14 09:59:41 by clira-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_init_img(t_data *img)
{
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = (int *)mlx_get_data_addr(img->img, \
			&img->bpp, &img->len_line, &img->endian);
}

int	ft_config_env(t_data *img)
{
	img->mlx = mlx_init();
	if (!(img->mlx))
	{
		perror("mlx_init error");
		exit(0);
	}
	img->mlx_win = mlx_new_window(img->mlx, \
		WIDTH, HEIGHT, "to infinity and beyond :)");
	img->type = img->argv[1][0];
	img->g.infinity = 100;
	if (img->type == 'j')
	{
		img->num_complex[0] = ft_atof(img->argv[2]);
		img->num_complex[1] = ft_atof(img->argv[3]);
	}
	return (0);
}

void	ft_exec_window(t_data *img)
{
	mlx_hook(img->mlx_win, DestroyNotify, \
		StructureNotifyMask, ft_close_win, img);
	mlx_mouse_hook(img->mlx_win, ft_scroll_zoom, img);
	mlx_key_hook(img->mlx_win, ft_key_escape, img);
	mlx_loop(img->mlx);
}

int	ft_refresh_window(t_data *img)
{
	mlx_do_sync(img->mlx);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

double	ft_map(double x, double in_max, double out[2])
{
	double	ret;
	double	a;
	double	b;
	double	in_min;

	in_min = 0;
	a = (out[0] - out[1]) / (in_min - in_max);
	b = ((out[0] * in_min) - in_max * out[0]) / (in_min - in_max);
	ret = a * x + b;
	return (ret);
}
