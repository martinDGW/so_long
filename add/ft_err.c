/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:08:04 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/15 16:13:06 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_err(t_data *data, int fd)
{
	close (fd);
	if (data)
		ft_free(data);
	write(1, "Error\n", 6);
	return (0);
}

int	ft_err_map(t_data *data, int fd)
{
	close (fd);
	if (data)
	{
		if (data->items)
			free(data->items);
		if (data->vars)
			free(data->vars);
		if (data->tiles)
			free(data->tiles);
		if (data->player)
			free(data->player);
	}
	if (data)
		free(data);
	write(1, "Error\n", 6);
	return (0);
}
