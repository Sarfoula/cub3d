/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:30:39 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/09 20:33:33 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Check that the line is empty
*/
bool	line_empty(char *line)
{
	int		i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i])
		return (false);
	return (true);
}

static void	init_textures(t_textures *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->east = NULL;
	textures->west = NULL;
	textures->floor = NULL;
	textures->ceiling = NULL;
}

static bool	fill_textures(t_textures *textures, char **textures_info)
{
	int	i;

	i = 0;
	while (textures_info[i])
	{
		if (ft_strlen(textures_info[i]) == 1)
			return (false);
		else if (textures->north == NULL && is_north(textures_info[i]))
			textures->north = textures_info[i];
		else if (textures->south == NULL && is_south(textures_info[i]))
			textures->south = textures_info[i];
		else if (textures->east == NULL && is_east(textures_info[i]))
			textures->east = textures_info[i];
		else if (textures->west == NULL && is_west(textures_info[i]))
			textures->west = textures_info[i];
		else if (textures->floor == NULL && is_floor(textures_info[i]))
			textures->floor = textures_info[i];
		else if (textures->ceiling == NULL && is_ceiling(textures_info[i]))
			textures->ceiling = textures_info[i];
		i++;
	}

}

bool	get_textures(int fd, t_textures *textures)
{
	int		line_parsed;
	char	*line;
	char	**textures_info;

	line_parsed = 0;
	init_textures(textures);
	textures_info = malloc(sizeof(char *) * 7);
	while (line_parsed < 6)
	{
		line = get_next_line(fd);
		if (line_empty(line) == false)
		{
			textures_info[line_parsed] = line;
			line_parsed++;
		}
		texture_info = NULL;
	}
	if (fill_textures(textures, textures_info) == false)
	{
		while (line_parsed-- >= 0)
			free(textures_info[line_parsed]);
		free(textures_info);
		return (false);
	}
	return (true);
}
