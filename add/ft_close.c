/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:31:15 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/15 15:03:27 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->vars->mlx, data->vars->win);
	ft_free(data);
	printf("\nYou didn't let Alice drop in le trou!\n\n");
	exit(EXIT_SUCCESS);
}
