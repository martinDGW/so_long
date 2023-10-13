/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:19:12 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/15 14:56:33 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	struct_init(t_data *data)
{
	data->items = malloc(sizeof(t_items) + 1);
	data->vars = malloc(sizeof(t_vars) + 1);
	data->tiles = malloc(sizeof(t_tiles) + 1);
	data->player = malloc(sizeof(t_player) + 1);
	if (!data->items || ! data->vars || !data->tiles || !data->player)
		return (0);
	return (1);
}

int	game_init(t_data *data, int fd)
{
	if (!map_init(data, fd))
	{
		data->items->valid = 0;
		return (0);
	}
	check_err(data);
	exit_init(data, data->map);
	player_pos(data, data->map);
	init_x_y_max(data);
	data->step = 0;
	data->ct = 0;
	return (1);
}
