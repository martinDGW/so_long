/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rabbit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:33:03 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/15 15:26:51 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	step_rabbit(void)
{
	static int	step;
	static int	last_step;

	if (step == 0)
	{
		last_step = step;
		step++;
	}
	else if (step == 2)
	{
		last_step = step;
		step--;
	}
	else if (step == 1 && last_step == 0)
	{
		last_step = step;
		step++;
	}
	else if (step == 1 && last_step == 2)
	{
		last_step = step;
		step--;
	}
	return (step);
}

void	anime_rabbit(t_vars *vars, t_tiles *tiles)
{
	int	step;

	step = step_rabbit();
	if (step == 0)
		tiles->collec = mlx_xpm_file_to_image(vars->mlx, RABBIT_D,
				tiles->x, tiles->y);
	else if (step == 1)
		tiles->collec = mlx_xpm_file_to_image(vars->mlx, RABBIT_M,
				tiles->x, tiles->y);
	else if (step == 2)
		tiles->collec = mlx_xpm_file_to_image(vars->mlx, RABBIT_U,
				tiles->x, tiles->y);
}
