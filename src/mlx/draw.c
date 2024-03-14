/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:34:02 by yallo             #+#    #+#             */
/*   Updated: 2024/03/14 12:38:24 by yallo            ###   ########.fr       */
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

void	trace(t_data *data, int x, int y1, int y2)
{
	int	color;

	if (y1 == 0)
		color = data->map.textures.ceiling.color;
	else
		color = data->map.textures.floor.color;
	while (y1 < y2)
	{
		my_pixel_put(data->mlx.img, x, y1, color);
		y1++;
	}
}

void	square(t_data data, int size, int x, int y)
{
	int	i;
	int	j;

	i = x;
	while (i < x + size)
	{
		j = y;
		while (j < y + size)
		{
			my_pixel_put(data.mlx.img, i, j, data.ray.color);
			j++;
		}
		i++;
	}
}

void	map(t_data data, int i, int j)
{
	data.ray.color = 0xf808080;
	if (data.map.str_rectangle[i][j] != 'x')
	{
		square(data, 16, j * 16, i * 16);
		if (data.map.str_rectangle[i][j] == '1')
		{
			data.ray.color = 0xfFFFFFF;
			square(data, 15, j * 16, i * 16);
		}
		else
		{
			data.ray.color = 0xf000000;
			square(data, 15, j * 16, i * 16);
		}
	}
}

void	minimap(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.map.nbr_line)
	{
		j = 0;
		while (j < data.map.nbr_column)
		{
			map(data, i, j);
			j++;
		}
		i++;
	}
	data.ray.color = 0xfFF0000;
	square(data, 5, data.player.posy * 16 - 3, data.player.posx * 16 - 3);
}
