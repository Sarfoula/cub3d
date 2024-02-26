/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:58:13 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/26 12:19:11 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @return true if the tile we want to check is on the border of the rectangular map
*/
static bool	on_map_border(int i, int j, t_map *map)
{
	if (i == 0)
		return (true);
	if (i == map->nbr_line)
		return (true);
	if (j == 0)
		return (true);
	if (j == map->nbr_column)
		return (true);
	return (false);
}

/**
 * Check the adjacent tiles of the map
 * If there is NOTHING next to it, return false 
*/
static bool	 check_adjacent_tiles(char **map, int i, int j)
{
	if (map[i + 1][j] == NOTHING || map[i - 1][j] == NOTHING \
	|| map[i][j + 1] == NOTHING || map[i][j - 1] == NOTHING)
		return (false);
	return (true);
}

bool	check_map_closed(t_map * map, char **map_rectangle)
{
	int	i;
	int	j;
 
	i = 0;
	while (map_rectangle[i])
	{
		j = 0;
		if (map_rectangle[i][j] == '0' || is_player(map_rectangle[i][j]) == true)
		{
			if (on_map_border(i, j, map) == true)
			{
				ft_printf(2, ERR_MAP_CLOSED);
				return (false);
			}
			if (check_adjacent_tiles(map_rectangle, i, j) == false)
			{
				ft_printf(2, ERR_MAP_CLOSED);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
