/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:48:09 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/04 18:17:52 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map_str(t_map *map)
{
	int	i;

	i = 0;
	if (!map->str)
		return ;
	while (map->str[i])
	{
		free(map->str[i]);
		i++;
	}
	free(map->str);
}

static void	free_map_str_rectangle(t_map *map)
{
	int	i;

	i = 0;
	while (map->str_rectangle[i])
	{
		free(map->str_rectangle[i]);
		i++;
	}
	free(map->str_rectangle);
}

void	free_map(t_map *map)
{
	free_map_str(map);
	free_map_str_rectangle(map);
}
