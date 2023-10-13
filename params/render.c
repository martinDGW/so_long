/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:16:14 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/15 15:25:18 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_frame(t_data *data)
{
	if (data->loop == 2000)
	{
		anime_rabbit(data->vars, data->tiles);
		data->loop = 0;
		put_imgs(data, data->tiles, data->vars, data->map);
	}
	else
		data->loop++;
	return (1);
}
