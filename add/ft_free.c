/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:04:41 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/15 15:09:13 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (data->map[i])
			free(data->map[i]);
		i++;
	}
	if (data->map)
		free(data->map);
	if (data->items)
		free(data->items);
	if (data->vars)
		free(data->vars);
	if (data->tiles)
		free(data->tiles);
	if (data->player)
		free(data->player);
	if (data)
		free(data);
}
