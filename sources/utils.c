/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:41:37 by clira-ne          #+#    #+#             */
/*   Updated: 2024/04/12 21:29:14 by clira-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

float	ft_atof(const char *str)
{
	float	num_all;
	float	dec;
	float	sign;
	int		i;

	num_all = 0.0;
	dec = 0.0;
	sign = 1.0;
	while (ft_isspace(*str) || *str == '-')
	{
		if (*str == '-')
			sign = -1.0;
		str++;
	}
	while (ft_isdigit(*str))
		num_all = num_all * 10 + (*str++ - '0');
	i = -1;
	if (*str == '.' && *str++)
	{
		while (ft_isdigit(*str))
			dec += (pow(10, i--) * (*str++ - '0'));
	}
	return (sign * (num_all + dec));
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (8192);
	else
		return (0);
}
