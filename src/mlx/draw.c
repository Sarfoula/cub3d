/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:34:02 by yallo             #+#    #+#             */
/*   Updated: 2024/03/06 15:29:50 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	my_mlx_pixel_put(t_image img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= screenwidth || y < 0 || y >= screenheight)
		return (1);
	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
	return (0);
}

void	trace(t_image img, int x1, int y1, int x2, int y2, int color)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int erreur = dx - dy;
	int erreur2;

	while (x1 != x2 || y1 != y2)
	{
		if (my_mlx_pixel_put(img, x1, y1, color) == 1)
			return ;
		erreur2 = 2 * erreur;
		if (erreur2 > -dy)
		{
			erreur -= dy;
			x1 += sx;
		}
		if (erreur2 < dx)
		{
			erreur += dx;
			y1 += sy;
		}
	}
}

void square(t_data *data, int sizex, int sizey, int x, int y, int color)
{
	int	i;
	int	j;

	i = x;
	while (i < x + sizex)
	{
		j = y;
		while (j < y + sizey)
		{
			my_mlx_pixel_put(data->mlx.img, i, j, color);
			j++;
		}
		i++;
	}
}

void minimap(t_data *data)
{
	for (int i = 0; i < data->map.nbr_line; i++)
	{
		for (int j = 0; j < data->map.nbr_column; j++)
		{
			if (data->map.str_rectangle[i][j] == 'x')
				break ;
			square(data, 16, 16, j * 16, i * 16, 0xf808080);
			if (data->map.str_rectangle[i][j] == '1')
				square(data, 15, 15, j * 16, i * 16, 0xfFFFFFF);
			else
				square(data, 15, 15, j * 16, i * 16, 0xf000000);
		}
	}
	square(data, 5, 5, data->player.posY * 16 - 3, data->player.posX * 16 - 3, 0xfFF0000);
}
