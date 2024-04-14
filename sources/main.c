/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:51:47 by clira-ne          #+#    #+#             */
/*   Updated: 2024/04/14 10:12:40 by clira-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static	void	error_handler(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_putstr_fd("The available sets are:\n", 1);
		ft_putstr_fd("mandelbrot;\njulia;\n", 1);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "mandelbrot", 11) != 0
		&& (!(ft_strncmp(argv[1], "julia", 6) == 0 && argc > 3)))
	{
		if (ft_strncmp(argv[1], "julia", 6) == 0)
		{
			ft_putstr_fd("Julia needs two arguments.", 1);
			ft_putstr_fd("Ex: ./fractol julia <n real> <n imaginary>\n", 1);
			ft_putstr_fd("That is: ./fractol julia -0.835 -0.2321\n", 1);
			exit(EXIT_FAILURE);
		}
		else
		{
			ft_putstr_fd("Invalid option. The available sets are:\n", 1);
			ft_putstr_fd("mandelbrot;\njulia;\n", 1);
			exit(EXIT_FAILURE);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_data	img;

	error_handler(argc, argv);
	img.g.zoom = 1;
	img.argv = argv;
	ft_config_env(&img);
	ft_init_img(&img);
	ft_fractol(&img, 0);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	ft_exec_window(&img);
	return (EXIT_SUCCESS);
}
