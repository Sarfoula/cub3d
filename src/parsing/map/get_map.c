/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:17:35 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/20 12:26:41 by tbarde-c         ###   ########.fr       */
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
	return (map);
}

void	substract_spaces(t_map *map)
{
	int	index;
	int	substract;
	int	i;

	i = 0;
	substract = 0;
	index = map->longest_line_index;
	while (map->str[index][i] == ' ')
	{
		substract++;
		i++;
	}
	while (map->str[index][i])
		i++;
	i--;
	while (map->str[index][i] == ' ' && i >= 0)
	{
		i--;
		substract++;
	}
	map->nbr_column -= substract;
}

void	set_column_nbr(t_map *map)
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
	substract_spaces(map);
}

void	set_line_nbr(t_map *map)
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
	map->str = ft_split(one_line_map, '\n');
	set_column_nbr(map);
	set_line_nbr(map);
	free(one_line_map);
	return (true);
}
