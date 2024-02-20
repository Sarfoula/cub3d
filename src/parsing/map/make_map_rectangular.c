/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_rectangular.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:59:18 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/20 15:33:14 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Copy the map we already parsed, replacing spaces by 'x' to make it more visual
*/
static void	copy_map(t_map *map, int i, int *j)
{
	while (map->str[i][*j])
	{
		if (map->str[i][*j] != ' ')
			map->str_rectangle[i][*j] = map->str[i][*j];
		else
			map->str_rectangle[i][*j] = NOTHING;
		*j += 1;
	}
}

/**
 * Add 'x' char at the end of the line to make the map a perfect rectangle
*/
static void	fill_end_column(t_map *map, int i, int *j)
{
	while (*j < map->nbr_column)
	{
		map->str_rectangle[i][*j] = NOTHING;
		*j += 1;
	}
}

/**
 * Fill the map with 'x' so that it ends up being a rectangle
 * We'll then know that 'x' means nothing to create
*/
void	make_map_rectangular(t_map *map)
{
	int	i;
	int	j;

	map->str_rectangle = malloc(sizeof(char *) * map->nbr_line + 1);
	map->str_rectangle[map->nbr_line] = NULL;
	i = 0;
	while (map->str[i])
	{
		j = 0;
		map->str_rectangle[i] = malloc(sizeof(char) * map->nbr_column + 1);
		copy_map(map, i, &j);
		fill_end_column(map, i, &j);
		map->str_rectangle[i][j] = '\0';
		i++;
	}
}
