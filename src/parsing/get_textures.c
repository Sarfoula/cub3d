/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:30:39 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/10 20:45:49 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_textures(t_textures *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->east = NULL;
	textures->west = NULL;
	textures->floor.rgb_str = NULL;
	textures->ceiling.rgb_str = NULL;
	textures->floor.red = -1;
	textures->floor.green = -1;
	textures->floor.blue = -1;
	textures->ceiling.red = -1;
	textures->ceiling.green = -1;
	textures->ceiling.blue = -1;
}

/**
 * Check the identifier of the line and fill the t_textures struct
 * if we can't recognie the identifier, we return false
 * if we identified all 6 identifiers, we return true
*/
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
		else if (textures->floor.rgb_str == NULL && is_floor(textures_info[i]))
			textures->floor.rgb_str = textures_info[i];
		else if (textures->ceiling.rgb_str == NULL && \
		is_ceiling(textures_info[i]))
			textures->ceiling.rgb_str = textures_info[i];
		else
			return (false);
		i++;
	}
	return (true);
}

/**
 * Free textures_info and textures_info[0] -> textures_info[line_parsed]
*/
static void	free_textures_info(int line_parsed, char **textures_info)
{
	while (line_parsed-- > 0)
		free(textures_info[line_parsed]);
	free(textures_info);
}

/**
 * Tries to duplicate six lines from the .cub file
 * If the line is not empty :
 * duplicate line without the beginning space
*/
static int	dup_six_lines(char **textures_info, int fd)
{
	char	*line;
	int		line_parsed;
	int		space_number;

	line_parsed = 0;
	line = get_next_line(fd);
	while (line_parsed < 6 && line)
	{
		space_number = 0;
		if (line_empty(line) == false)
		{
			while (ft_isspace(line[space_number]) == true)
				space_number++;
			textures_info[line_parsed] = ft_strdup(line + space_number);
			line_parsed++;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (line_parsed);
}

/**
 * Try to get the textures info from the .cub
 * If we fail, return false, else return true
*/
bool	get_textures(int fd, t_textures *textures)
{
	int		line_parsed;
	char	*line;
	char	**textures_info;

	line_parsed = 0;
	init_textures(textures);
	textures_info = malloc(sizeof(char *) * 7);
	line_parsed = dup_six_lines(textures_info, fd);
	if (line_parsed < 6)
	{
		free_textures_info(line_parsed, textures_info);
		return (ft_printf(2, ERR_TEXTURES_NBR), false);
	}
	if (fill_textures(textures, textures_info) == false)
	{
		free_textures_info(line_parsed, textures_info);
		return (ft_printf(2, ERR_TEXTURES_CONTENT), false);
	}
	free(textures_info);
	return (true);
}
