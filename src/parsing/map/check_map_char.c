/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:45:56 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/20 15:31:55 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' ');
}

static void	update_spawn_info(t_map *map, int i, int j, int *player_spawn)
{
	map->spawn_x = j;
	map->spawn_y = i;
	*player_spawn += 1;
}

/**
 * Check if the char of the map are valid 
 * Also check if we only have one player spawn
*/
bool	check_map_char(t_map *map)
{
	int	player_spawn;
	int	i;
	int	j;

	player_spawn = 0;
	i = 0;
	j = 0;
	while (map->str[i])
	{
		j = 0;
		while (map->str[i][j])
		{
			if (is_player(map->str[i][j]) == true)
				update_spawn_info(map, i, j, &player_spawn);
			else if (valid_char(map->str[i][j]) == false)
				return (ft_printf(2, ERR_MAP_CHAR, map->str[i][j]), false);
			j++;
		}
		i++;
	}
	if (player_spawn != 1)
		return (ft_printf(2, ERR_MAP_SPAWN_NBR), false);
	return (true);
}
