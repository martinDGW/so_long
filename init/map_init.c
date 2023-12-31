/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:07:01 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/15 15:16:42 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_init(t_data *data, int fd)
{
	char	*str;
	char	*to_free;
	char	*buffer;

	str = NULL;
	buffer = get_next_line(fd);
	if (!buffer)
		return (0);
	while (buffer)
	{
		to_free = str;
		str = ft_strjoin(str, buffer);
		if (to_free)
			free(to_free);
		if (buffer)
			free(buffer);
		buffer = get_next_line(fd);
	}
	data->map = ft_split(str, '\n');
	free(str);
	return (1);
}
