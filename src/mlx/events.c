/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:24:44 by yallo             #+#    #+#             */
/*   Updated: 2024/03/13 16:07:08 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vertical(int key, t_data *data, t_player *player)
{
	if (key == 119)
	{
		if (data->map.str_rectangle[(int)(player->posx + player->dirx * 0.3)][\
		(int)(player->posy)] != '1')
			player->posx += player->dirx * 0.3;
		if (data->map.str_rectangle[(int)(player->posx)][(int)(player->posy + \
		player->diry * 0.3)] != '1')
			player->posy += player->diry * 0.3;
	}
	if (key == 115)
	{
		if (data->map.str_rectangle[(int)(player->posx - player->dirx * 0.3)][\
		(int)(player->posy)] != '1')
			player->posx -= player->dirx * 0.3;
		if (data->map.str_rectangle[(int)(player->posx)][(int)(player->posy - \
		player->diry * 0.3)] != '1')
			player->posy -= player->diry * 0.3;
	}
}

void	horizontal(int key, t_data *data, t_player *player)
{
	if (key == 97)
	{
		if (data->map.str_rectangle[(int)(player->posx - player->planex * 0.3)][\
		(int)(player->posy)] != '1')
			player->posx -= player->planex * 0.3;
		if (data->map.str_rectangle[(int)(player->posx)][(int)(player->posy - \
		player->planey * 0.3)] != '1')
			player->posy -= player->planey * 0.3;
	}
	if (key == 100)
	{
		if (data->map.str_rectangle[(int)(player->posx + player->planex * 0.3)][\
		(int)(player->posy)] != '1')
			player->posx += player->planex * 0.3;
		if (data->map.str_rectangle[(int)(player->posx)][(int)(player->posy + \
		player->planey * 0.3)] != '1')
			player->posy += player->planey * 0.3;
	}
}

void	rotation(int key, t_player *player)
{
	double	olddirx;
	double	oldplanex;

	if (key == 65361)
	{
		olddirx = player->dirx;
		player->dirx = player->dirx * cos(0.08) - player->diry * sin(0.08);
		player->diry = olddirx * sin(0.08) + player->diry * cos(0.08);
		oldplanex = player->planex;
		player->planex = player->planex * cos(0.08) - player->planey * \
			sin(0.08);
		player->planey = oldplanex * sin(0.08) + player->planey * cos(0.08);
	}
	if (key == 65363)
	{
		olddirx = player->dirx;
		player->dirx = player->dirx * cos(-0.08) - player->diry * sin(-0.08);
		player->diry = olddirx * sin(-0.08) + player->diry * cos(-0.08);
		oldplanex = player->planex;
		player->planex = player->planex * cos(-0.08) - player->planey * \
			sin(-0.08);
		player->planey = oldplanex * sin(-0.08) + player->planey * cos(-0.08);
	}
}

int	key_input(int key, t_data *data)
{
	rotation(key, &(data)->player);
	vertical(key, data, &(data)->player);
	horizontal(key, data, &(data)->player);
	if (key == 65307)
		mlx_loop_end(data->mlx.mlx);
	if (key == 112)
	{
		if (data->map.minimap == 0)
			data->map.minimap = 1;
		else
			data->map.minimap = 0;
	}
	return (0);
}
