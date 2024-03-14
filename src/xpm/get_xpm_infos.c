/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xpm_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:26:36 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/14 12:11:22 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * get the following infos from the xpm file :
 * - Width in pixel number
 * - Height in pixel number
 * - Number of different pixel colors
 * MEASURE = NUMBER OF PIXELS
*/
int	get_xpm_infos(t_cardinal *xpm)
{
	char	*line;
	char	**temp;
	int		fd;

	fd = xpm->fd;
	line = get_next_line(fd);
	if (!line)
		return (ft_printf(2, ERR_XPM_EMPTY, xpm->cardinal_str), NO_INFO);
	while (line)
	{
		if (line[0] == '"')
		{
			temp = ft_split(line + 1, ' ');
			xpm->width = ft_atoi(temp[0]);
			xpm->height = ft_atoi(temp[1]);
			xpm->nb_of_colors = ft_atoi(temp[2]);
			free_split(temp);
			free(line);
			return (RECOVERED);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (NO_INFO);
}
