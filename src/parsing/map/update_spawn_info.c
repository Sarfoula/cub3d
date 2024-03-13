/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_spawn_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:57:17 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/13 13:07:06 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	spawn_north(t_player *player)
{
	player->dirX = -1;
	player->dirY = 0;
	player->planeX = 0;
	player->planeY = 0.66;
}

static void	spawn_south(t_player *player)
{
	player->dirX = 1;
	player->dirY = 0;
	player->planeX = 0;
	player->planeY = -0.66;
}

static void	spawn_east(t_player *player)
{
	player->dirX = 0;
	player->dirY = 1;
	player->planeX = 0.66;
	player->planeY = 0;
}

static void	spawn_west(t_player *player)
{
	player->dirX = 0;
	player->dirY = -1;
	player->planeX = -0.66;
	player->planeY = 0;
}

void	update_spawn_info(t_map *map, t_player *player, int i, int j)
{
	char	c;

	c = map->str_rectangle[i][j];
	player->posX = i + 0.3;
	player->posY = j + 0.3;
	if (c == 'N')
		spawn_north(player);
	else if (c == 'S')
		spawn_south(player);
	else if (c == 'E')
		spawn_east(player);
	else if (c == 'W')
		spawn_west(player);
}
