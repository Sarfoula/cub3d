/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:24:44 by yallo             #+#    #+#             */
/*   Updated: 2024/03/07 14:07:15 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_input(int key, t_data *data)
{
	double moveSpeed = 0.3;
	double rotSpeed = 0.05;

	if (key == 65307)
		mlx_loop_end(data->mlx.mlx);
	if (key == 119) //W
	{
		if (data->map.str_rectangle[(int)(data->player.posX + data->player.dirX * moveSpeed)][(int)(data->player.posY)] != '1')
			data->player.posX += data->player.dirX * moveSpeed;
		if (data->map.str_rectangle[(int)(data->player.posX)][(int)(data->player.posY + data->player.dirY * moveSpeed)] != '1')
			data->player.posY += data->player.dirY * moveSpeed;
	}
	if (key == 115) //S
	{
		if (data->map.str_rectangle[(int)(data->player.posX - data->player.dirX * moveSpeed)][(int)(data->player.posY)] != '1')
			data->player.posX -= data->player.dirX * moveSpeed;
		if (data->map.str_rectangle[(int)(data->player.posX)][(int)(data->player.posY - data->player.dirY * moveSpeed)] != '1')
			data->player.posY -= data->player.dirY * moveSpeed;
	}
	if (key == 97) //A
	{
		if (data->map.str_rectangle[(int)(data->player.posX - data->player.planeX * moveSpeed)][(int)(data->player.posY)] != '1')
			data->player.posX -= data->player.planeX * moveSpeed;
		if (data->map.str_rectangle[(int)(data->player.posX)][(int)(data->player.posY - data->player.planeY * moveSpeed)] != '1')
			data->player.posY -= data->player.planeY * moveSpeed;
	}
	if (key == 100) //D
	{
		if (data->map.str_rectangle[(int)(data->player.posX + data->player.planeX * moveSpeed)][(int)(data->player.posY)] != '1')
			data->player.posX += data->player.planeX * moveSpeed;
		if (data->map.str_rectangle[(int)(data->player.posX)][(int)(data->player.posY + data->player.planeY * moveSpeed)] != '1')
			data->player.posY += data->player.planeY * moveSpeed;
	}
	if (key == 65361) //<--
	{
		double olddirX = data->player.dirX;
		data->player.dirX = data->player.dirX * cos(rotSpeed) - data->player.dirY * sin(rotSpeed);
		data->player.dirY = olddirX * sin(rotSpeed) + data->player.dirY * cos(rotSpeed);
		double oldPlaneX = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(rotSpeed)  - data->player.planeY * sin(rotSpeed);
		data->player.planeY = oldPlaneX * sin(rotSpeed) + data->player.planeY * cos(rotSpeed);
	}
	if (key == 65363) //-->
	{
		double olddirX = data->player.dirX;
		data->player.dirX = data->player.dirX * cos(-rotSpeed) - data->player.dirY * sin(-rotSpeed);
		data->player.dirY = olddirX * sin(-rotSpeed) + data->player.dirY * cos(-rotSpeed);
		double oldPlaneX = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(-rotSpeed) - data->player.planeY * sin(-rotSpeed);
		data->player.planeY = oldPlaneX * sin(-rotSpeed) + data->player.planeY * cos(-rotSpeed);
	}
	if (key == 112) //P
	{
		if (data->map.minimap == 0)
			data->map.minimap = 1;
		else
			data->map.minimap = 0;
		// printf("posX = %f posY = %f\n", data->player.posX, data->player.posY);
		// printf("dirX = %f dirY = %f\n\n", data->player.dirX, data->player.dirY);
		// printf("x%f y%f\n\n", data->player.planeX, data->player.planeY);
	}
	return (0);
}
