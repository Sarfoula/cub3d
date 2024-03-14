/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:59:24 by yallo             #+#    #+#             */
/*   Updated: 2024/03/14 12:05:13 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		return (false);
	data->mlx.window = mlx_new_window(data->mlx.mlx, WIDTH, \
		HEIGHT, "cub3d");
	if (!data->mlx.window)
		return (false);
	data->mlx.img.img = mlx_new_image(data->mlx.mlx, WIDTH, \
		HEIGHT);
	if (!data->mlx.img.img)
		return (false);
	data->mlx.img.addr = mlx_get_data_addr(data->mlx.img.img, \
		&data->mlx.img.bpp, &data->mlx.img.line_len, &data->mlx.img.endian);
	data->map.textures.ceiling.color = \
		rgb_to_int(data->map.textures.ceiling.red, data->map.textures.ceiling.green, \
		data->map.textures.ceiling.blue);
	data->map.textures.floor.color = \
		rgb_to_int(data->map.textures.floor.red, data->map.textures.floor.green, \
		data->map.textures.floor.blue);
	return (true);
}

void	free_mlx(t_mlx mlx)
{
	if (mlx.window)
		mlx_destroy_window(mlx.mlx, mlx.window);
	if (mlx.img.img)
		mlx_destroy_image(mlx.mlx, mlx.img.img);
	if (mlx.mlx)
	{
		mlx_destroy_display(mlx.mlx);
		free(mlx.mlx);
	}
}
