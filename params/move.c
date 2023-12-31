/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:00:23 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/15 16:41:25 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_data *data)
{
	ft_step(data);
	dir_up(data->vars->mlx, data->tiles, data->step);
	if (data->map[data->player->y - 1][data->player->x] != '1')
	{
		if (data->map[data->player->y - 1][data->player->x] == 'C')
			data->items->collec -= 1;
		data->map[data->player->y][data->player->x] = '0';
		data->player->y -= 1;
		data->map[data->player->y][data->player->x] = 'P';
		data->ct++;
		printf("Nb de déplacemnts : %d\n", data->ct);
	}
	if (data->map[data->e_y][data->e_x] != 'P')
		data->map[data->e_y][data->e_x] = 'E';
}

void	move_down(t_data *data)
{
	ft_step(data);
	dir_down(data->vars->mlx, data->tiles, data->step);
	if (data->map[data->player->y + 1][data->player->x] != '1')
	{
		if (data->map[data->player->y + 1][data->player->x] == 'C')
			data->items->collec -= 1;
		data->map[data->player->y][data->player->x] = '0';
		data->player->y += 1;
		data->map[data->player->y][data->player->x] = 'P';
		data->ct++;
		printf("Nb de déplacemnts : %d\n", data->ct);
	}
	if (data->map[data->e_y][data->e_x] != 'P')
		data->map[data->e_y][data->e_x] = 'E';
}

void	move_right(t_data *data)
{
	ft_step(data);
	dir_right(data->vars->mlx, data->tiles, data->step);
	if (data->map[data->player->y][data->player->x + 1] != '1')
	{
		if (data->map[data->player->y][data->player->x + 1] == 'C')
			data->items->collec -= 1;
		data->map[data->player->y][data->player->x] = '0';
		data->player->x += 1;
		data->map[data->player->y][data->player->x] = 'P';
		data->ct++;
		printf("Nb de déplacemnts : %d\n", data->ct);
	}
	if (data->map[data->e_y][data->e_x] != 'P')
		data->map[data->e_y][data->e_x] = 'E';
}

void	move_left(t_data *data)
{
	ft_step(data);
	dir_left(data->vars->mlx, data->tiles, data->step);
	if (data->map[data->player->y][data->player->x - 1] != '1')
	{
		if (data->map[data->player->y][data->player->x - 1] == 'C')
			data->items->collec -= 1;
		data->map[data->player->y][data->player->x] = '0';
		data->player->x -= 1;
		data->map[data->player->y][data->player->x] = 'P';
		data->ct++;
		printf("Nb de déplacemnts : %d\n", data->ct);
	}
	if (data->map[data->e_y][data->e_x] != 'P')
		data->map[data->e_y][data->e_x] = 'E';
}
