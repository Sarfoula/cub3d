/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:45:56 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/28 13:00:50 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' ');
}

static void	update_spawn_info(t_map *map, int i, int j, int *player_spawn)
{
	char	c;

	map->player.x = j;
	map->player.y = i;
	c = map->str[i][j];
	if (c == 'N')
		map->player.angle = 1.6;
	else if (c == 'S')
		map->player.angle = 4.7;
	else if (c == 'E')
		map->player.angle = 0;
	else if (c == 'W')
		map->player.angle = 3.1;
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
