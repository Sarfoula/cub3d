/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:59:24 by yallo             #+#    #+#             */
/*   Updated: 2024/02/28 13:53:54 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool init_mlx(t_data *data)
{
	data->map.player.x *= 64;
	data->map.player.y *= 64;
	// data->map.nbr_column -= 1;
	// data->map.nbr_line -= 1;
	data->map.player.angle = 1.6;
	data->map.player.dx = 0;		//We say that a digit (1/0)
	data->map.player.dy = 64;		//is a square of 64x64
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		return (false);
	data->mlx.window = mlx_new_window(data->mlx.mlx, SIZEX, SIZEY, "cub3d");
	if (!data->mlx.window)
		return (false);
	data->mlx.img.img = mlx_new_image(data->mlx.mlx, SIZEX, SIZEY);
	if (!data->mlx.img.img)
		return (false);
	data->mlx.img.addr = mlx_get_data_addr(data->mlx.img.img, &data->mlx.img.bpp, \
		&data->mlx.img.line_len, &data->mlx.img.endian);
	return (true);
}

void free_mlx(t_mlx mlx)
{
	if (mlx.window)
			mlx_destroy_window(mlx.mlx, mlx.window);
	if (mlx.mlx)
	{
		mlx_destroy_display(mlx.mlx);
		free(mlx.mlx);
	}
}
