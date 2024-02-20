/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:50:17 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/20 12:43:40 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// static bool	check_spawn_location(t_map map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (map.str[i])
// 	{
// 		j = 0;
// 		while (map.str[i][j])
// 		{
// 			if (is_player(map.str[i][j]))
// 			{
// 				if (i == 0 || i == map.nbr_line || j == 0 )
// 				{
// 					ft_printf(2, ERR_MAP_SPAWN_LOC);
// 					return (false);
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (true);
// }

/**
 * Check that the map is valid :
 * - only allowed char, and only one player spawn
 * (we allow spaces at this point of the map checking)
 * - The map is closed
 * - the map has valid use of spaces
 * (no space inside the map, no tabs)
*/
bool	check_map(t_map map)
{
	if (check_map_char(map) == false)
		return (false);
	// if (check_spawn_location(map) == false)
	// 	return (false);
	/*if (check_map_closed(map) == false)
		return (false);
	if (check_map_spaces(map) == false)
		return (false);*/
	return (true);
}