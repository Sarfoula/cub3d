/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:34:02 by yallo             #+#    #+#             */
/*   Updated: 2024/03/14 00:29:20 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	my_pixel_put(t_image img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (1);
	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
	return (0);
}

void	trace(t_image img, int x, int y1, int y2, int color)
{
	while (y1 < y2)
	{
		my_pixel_put(img, x, y1, color);
		y1++;
	}
}

void	square(t_data *data, int size, int x, int y, int color)
{
	int	i;
	int	j;

	i = x;
	while (i < x + size)
	{
		j = y;
		while (j < y + size)
		{
			my_pixel_put(data->mlx.img, i, j, color);
			j++;
		}
		i++;
	}
}

void	minimap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.nbr_line)
	{
		j = 0;
		while (j < data->map.nbr_column)
		{
			if (data->map.str_rectangle[i][j] != 'x')
			{
				square(data, 16, j * 16, i * 16, 0xf808080);
				if (data->map.str_rectangle[i][j] == '1')
					square(data, 15, j * 16, i * 16, 0xfFFFFFF);
				else
					square(data, 15, j * 16, i * 16, 0xf000000);
			}
			j++;
		}
		i++;
	}
	square(data, 5, data->player.posy * 16 - 3, \
		data->player.posx * 16 - 3, 0xfFF0000);
}
