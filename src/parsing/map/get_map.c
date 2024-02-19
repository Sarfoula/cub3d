/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:17:35 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/19 14:24:16 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*skip_empty_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line_empty(line) == true && line)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

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

bool	get_map(int fd, char ***map)
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
	*map = ft_split(one_line_map, '\n');
	free(one_line_map);
	return (true);
}
