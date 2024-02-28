/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:34:02 by yallo             #+#    #+#             */
/*   Updated: 2024/02/27 17:53:09 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SIZEX || y < 0 || y >= SIZEY)
		return (1);
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
	return (0);
}

void	trace(t_image *img, int x1, int y1, int x2, int y2, int color)
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
