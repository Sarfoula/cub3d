/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:30:39 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/14 15:58:11 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_textures(t_textures *textures)
{
	textures->north.cardinal_str = NULL;
	textures->north.fd = -1;
	textures->north.rgb = NULL;
	textures->south.cardinal_str = NULL;
	textures->south.fd = -1;
	textures->south.rgb = NULL;
	textures->east.cardinal_str = NULL;
	textures->east.fd = -1;
	textures->east.rgb = NULL;
	textures->west.cardinal_str = NULL;
	textures->west.fd = -1;
	textures->west.rgb = NULL;
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
	if (line)
		free(line);
	return (line_parsed);
}

/**
 * Try to get the textures info from the .cub
 * If we fail, return false, else return true
*/
bool	get_textures(int fd, t_textures *textures)
{
	int		line_parsed;
	char	**textures_info;

	line_parsed = 0;
	init_textures(textures);
	textures_info = malloc(sizeof(char *) * 7);
	textures_info[6] = NULL;
	line_parsed = dup_six_lines(textures_info, fd);
	if (line_parsed < 6)
	{
		free_textures_info(line_parsed, textures_info);
		finish_reading_file(fd);
		return (ft_printf(2, ERR_TEXTURES_NBR), false);
	}
	remove_backslash_n(textures_info);
	if (fill_textures(textures, textures_info) == false)
	{
		free_textures_info(line_parsed, textures_info);
		finish_reading_file(fd);
		return (ft_printf(2, ERR_TEXTURES_CONTENT), false);
	}
	free(textures_info);
	return (true);
}
