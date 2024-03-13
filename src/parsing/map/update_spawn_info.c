/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_spawn_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:57:17 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/13 15:30:56 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	spawn_north(t_player *player)
{
	player->dirx = -1;
	player->diry = 0;
	player->planex = 0;
	player->planey = 0.66;
}

static void	spawn_south(t_player *player)
{
	player->dirx = 1;
	player->diry = 0;
	player->planex = 0;
	player->planey = -0.66;
}

static void	spawn_east(t_player *player)
{
	player->dirx = 0;
	player->diry = 1;
	player->planex = 0.66;
	player->planey = 0;
}

static void	spawn_west(t_player *player)
{
	player->dirx = 0;
	player->diry = -1;
	player->planex = -0.66;
	player->planey = 0;
}

void	update_spawn_info(t_map *map, t_player *player, int i, int j)
{
	char	c;

	c = map->str_rectangle[i][j];
	player->posx = i + 0.3;
	player->posy = j + 0.3;
	if (c == 'N')
		spawn_north(player);
	else if (c == 'S')
		spawn_south(player);
	else if (c == 'E')
		spawn_east(player);
	else if (c == 'W')
		spawn_west(player);
}
