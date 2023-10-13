/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:28:29 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/15 16:38:35 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_data	*data;
	int		fd;

	fd = open("./map/map1.ber", O_RDONLY);
	if (fd < 0)
		return (0);
	data = malloc(sizeof(*data) + 1);
	if (!data || !struct_init(data))
		return (ft_err(data, fd));
	if (!game_init(data, fd))
		return (ft_err_map(data, fd));
	if (data->items->valid == 0)
		return (ft_err(data, fd));
	close(fd);
	win_init(data);
	setup_tiles(data->tiles, data->vars->mlx);
	mlx_hook(data->vars->win, 2, 0, ft_key, data);
	mlx_hook(data->vars->win, 17, 0, ft_close, data);
	mlx_loop_hook(data->vars->mlx, render_frame, data);
	mlx_loop(data->vars->mlx);
	return (0);
}
