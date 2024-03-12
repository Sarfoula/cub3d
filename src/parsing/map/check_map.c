/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:50:17 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/12 17:04:38 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Check that the spawn location is valid :
 * - There is floor or wall surrounding the spawn
 * - The spawn is not located in the border of the map
*/
static bool	check_spawn_location(t_map *map, t_player *player)
{
	int	x;
	int	y;

	x = player->posX;
	y = player->posY;
	if (x == 0 || y == 0 || y == map->nbr_line || x == map->nbr_column)
	{
		ft_printf(2, ERR_MAP_SPAWN_LOC);
		return (false);
	}
	if (map->str_rectangle[x - 1][y] == NOTHING \
	|| map->str_rectangle[x + 1][y] == NOTHING \
	|| map->str_rectangle[x][y - 1] == NOTHING \
	|| map->str_rectangle[x][y + 1] == NOTHING \
	|| map->str_rectangle[x + 1][y] == '\0')
	{
		ft_printf(2, ERR_MAP_SPAWN_LOC);
		return (false);
	}
	return (true);
}

/**
 * Check that the map is valid :
 * - only allowed char, and only one player spawn
 * (we allow spaces at this point of the map checking)
 * - The map is closed
 * - the map has valid use of spaces
 * (no space inside the map, no tabs)
*/
bool	check_map(t_map *map, t_player *player)
{
	if (check_map_char(map, player) == false)
		return (false);
	if (check_spawn_location(map, player) == false)
		return (false);
	if (check_map_closed(map, map->str_rectangle) == false)
		return (false);
	return (true);
}
