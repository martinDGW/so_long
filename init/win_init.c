/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:26:38 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/15 15:22:13 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	win_init(t_data *data)
{
	init_x_y_max(data);
	data->vars->mlx = mlx_init();
	data->vars->win = mlx_new_window(data->vars->mlx,
			data->x_max * 64, data->y_max * 64, "Alice in wonderland");
}
