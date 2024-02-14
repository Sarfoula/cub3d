/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filepath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:07:01 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/02/14 12:59:40 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Remove the first two letters + space before the actual file path
 * If there is no path afterwards, return false
*/
static bool	remove_identifier(char **filepath)
{
	char	*temp;
	int		i;

	i = 2;
	temp = *filepath;
	while (ft_isspace((*filepath)[i]) == true)
		i++;
	if ((*filepath)[i] == '\0')
	{
		ft_printf(2, ERR_FILEPATH_CONTENT, *filepath);
		return (false);
	}
	*filepath = ft_strdup(*filepath + i);
	free(temp);
	return (true);
}

/**
 * Check if the file is a valid .xpm that can be opened and store it in the t_cardinal struct if it is
*/
static bool	get_check_fd(t_cardinal *cardinal)
{
	int	fd;

	if (ft_strstr_last(cardinal->cardinal_str, ".xpm") == false)
	{
		ft_printf(2, ERR_TEXTURES_XPM, cardinal->cardinal_str);
		return (false);
	}
	fd = open(cardinal->cardinal_str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(2, "file : '%s'\n", cardinal->cardinal_str);
		perror(ERR_OPEN);
		return (false);
	}
	cardinal->fd = fd;
	close(fd);
	return (true);
}

bool	check_filepath(t_cardinal *cardinal)
{
	if (remove_identifier(&cardinal->cardinal_str) == false)
		return (false);
	if (get_check_fd(cardinal) == false)
	 	return (false);
	return (true);
}