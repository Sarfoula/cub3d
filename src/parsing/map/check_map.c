/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:50:17 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/26 12:23:00 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Check that the spawn location is valid : 
 * - There is floor or wall surrounding the spawn
 * - The spawn is not located in the border of the map
*/
static bool	check_spawn_location(t_map *map)
{
	int	x;
	int	y;

	x = map->spawn_x;
	y = map->spawn_y;
	if (x == 0 || y == 0 || y + 1 == map->nbr_line)
	{
		ft_printf(2, ERR_MAP_SPAWN_LOC);
		return (false);
	}
	if (map->str_rectangle[y - 1][x] == NOTHING || map->str_rectangle[y + 1][x] == NOTHING \
	|| map->str_rectangle[y][x - 1] == NOTHING || map->str_rectangle[y][x + 1] == NOTHING \
	|| map->str_rectangle[y][x + 1] == '\0')
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
bool	check_map(t_map *map)
{
	if (check_map_char(map) == false)
		return (false);
	if (check_spawn_location(map) == false)
		return (false);
	if (check_map_closed(map, map->str_rectangle) == false)
		return (false);
	return (true);
}
