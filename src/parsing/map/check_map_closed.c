/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:58:13 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/26 13:18:22 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @return true if the tile we want to check is on the border 
 * of the rectangular map
*/
static bool	on_map_border(int i, int j, t_map *map)
{
	if (i == 0)
		return (true);
	if (i == map->nbr_line - 1)
		return (true);
	if (j == 0)
		return (true);
	if (j == map->nbr_column - 1)
		return (true);
	return (false);
}

/**
 * Check the adjacent tiles of the map
 * If there is NOTHING next to it, return false 
*/
static bool	check_adjacent_tiles(char **map, int i, int j)
{
	if (map[i + 1][j] == NOTHING || map[i - 1][j] == NOTHING \
	|| map[i][j + 1] == NOTHING || map[i][j - 1] == NOTHING)
		return (false);
	return (true);
}

bool	check_map_closed(t_map *map, char **map_rectangle)
{
	int	i;
	int	j;

	i = 0;
	while (map_rectangle[i])
	{
		j = 0;
		while (map_rectangle[i][j])
		{
			if (map_rectangle[i][j] == '0' || \
			is_player(map_rectangle[i][j]) == true)
			{
				if (on_map_border(i, j, map) == true)
					return (ft_printf(2, ERR_MAP_CLOSED), false);
				if (check_adjacent_tiles(map_rectangle, i, j) == false)
					return (ft_printf(2, ERR_MAP_CLOSED), false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
