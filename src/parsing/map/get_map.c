/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:17:35 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/06 15:25:19 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Copy each line from the File to the char ***
*/
static char	*copy_map_lines(char *line, int fd)
{
	char	*map;
	char	*temp;

	map = ft_strdup(line);
	free(line);
	line = get_next_line(fd);
	while (line_empty(line) == false && line)
	{
		temp = map;
		map = ft_strjoin(map, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (map);
}

static void	set_column_nbr(t_map *map)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	ret = 0;
	while (map->str[i])
	{
		j = 0;
		while (map->str[i][j])
			j++;
		if (j > ret)
		{
			map->longest_line_index = i;
			ret = j;
		}
		i++;
	}
	map->nbr_column = ret;
}

/**
 * Crop the beginning and ending spaces from the map lines
*/
static void	crop_map(t_map *map)
{
	int		i;
	char	*temp;

	i = 0;
	while (map->str[i])
	{
		temp = map->str[i];
		map->str[i] = ft_strtrim_ending(map->str[i], " ");
		free(temp);
		i++;
	}
}

static void	set_line_nbr(t_map *map)
{
	int	ret;

	ret = 0;
	while (map->str[ret])
		ret++;
	map->nbr_line = ret;
}

bool	get_map(int fd, t_map *map)
{
	char	*line;
	char	*one_line_map;

	line = skip_empty_lines(fd);
	if (!line)
	{
		ft_printf(2, ERR_MAP_NULL);
		return (false);
	}
	one_line_map = copy_map_lines(line, fd);
	if (finish_reading_file(fd) == true)
		return (free(one_line_map), false);
	map->str = ft_split(one_line_map, '\n');
	crop_map(map);
	set_line_nbr(map);
	set_column_nbr(map);
	make_map_rectangular(map);
	free(one_line_map);
	return (true);
}
