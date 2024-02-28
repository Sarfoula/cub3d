/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:24:44 by yallo             #+#    #+#             */
/*   Updated: 2024/02/28 11:24:17 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_input(int key, t_data *data)
{
	if (key == 65307)
		mlx_loop_end(data->mlx.mlx);
	if (key == 119) //up
	{
		data->map.player.y += data->map.player.dy / 10;
		data->map.player.x += data->map.player.dx / 10;
	}
	if (key == 115)//down
	{
		data->map.player.y -= data->map.player.dy / 10;
		data->map.player.x -= data->map.player.dx / 10;
	}
	if (key == 97)//left
	{
		data->map.player.angle -= 0.06;
		if (data->map.player.angle <= 0)
			data->map.player.angle += PI2;
		data->map.player.dx = cos(data->map.player.angle) * 100;
		data->map.player.dy = sin(data->map.player.angle) * 100;
	}
	if (key == 100)//right
	{
		data->map.player.angle += 0.06;
		if (data->map.player.angle >= PI2)
			data->map.player.angle -= PI2;
		data->map.player.dx = cos(data->map.player.angle) * 100;
		data->map.player.dy = sin(data->map.player.angle) * 100;
	}
	// if (key == 65363) //arrow right
	// if (key == 65361) //arrow left
	// if (key == 112) //P
	return (0);
}
