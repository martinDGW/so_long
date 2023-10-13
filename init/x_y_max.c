/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_y_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:08:28 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/15 15:21:27 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_xmax(char **map)
{
	int	x;

	if (ft_strlen(map[0]) < WIDTH)
		x = ft_strlen(map[0]);
	else
		x = WIDTH;
	return (x);
}

int	get_ymax(char **map)
{
	int	y;

	if (ft_modlen(map) < HEIGHT)
		y = ft_modlen(map);
	else
		y = HEIGHT;
	return (y);
}

void	init_x_y_max(t_data *data)
{
	data->x_max = get_xmax(data->map);
	data->y_max = get_ymax(data->map);
}
