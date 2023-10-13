/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:13:15 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/15 15:20:31 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*what_tiles(char c, t_tiles *tiles)
{
	if (c == '1')
		return (tiles->wall);
	else if (c == 'C')
		return (tiles->collec);
	else if (c == 'P')
		return (tiles->player);
	else if (c == 'E')
		return (tiles->end);
	return (tiles->empty);
}

int	get_camy(t_data *data)
{
	int	y;

	if (data->player->y - 5 <= 0)
		return (0);
	if (ft_modlen(data->map) < HEIGHT)
		return (0);
	if (ft_modlen(data->map) - data->player->y < HEIGHT - 4)
		y = ft_modlen(data->map) - HEIGHT;
	else
		y = data->player->y - 5;
	return (y);
}

int	get_camx(t_data *data)
{
	int	x;

	if (data->player->x - 5 <= 0)
		return (0);
	if (ft_strlen(data->map[0]) < WIDTH)
		return (0);
	if (ft_strlen(data->map[0]) - data->player->x < WIDTH - 4)
		x = ft_strlen(data->map[0]) - WIDTH;
	else
		x = data->player->x - 5;
	return (x);
}

void	put_imgs(t_data *data, t_tiles *tiles, t_vars *vars, char **map)
{
	int		x;
	int		y;
	int		i;
	int		j;
	void	*temp;

	player_pos(data, data->map);
	y = get_camy(data);
	i = -1;
	while (i++ < HEIGHT && map[y])
	{
		j = -1;
		x = get_camx(data);
		while (j++ < WIDTH && map[y][x])
		{
			temp = what_tiles(map[y][x], data->tiles);
			if (map[y][x] != '1')
				mlx_put_image_to_window(vars->mlx, vars->win, tiles->empty,
					j * 64, i * 64);
			mlx_put_image_to_window(vars->mlx, vars->win, temp, j * 64, i * 64);
			x++;
		}
		y++;
	}
}
