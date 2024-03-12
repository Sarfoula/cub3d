/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_xpm_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:49:00 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/12 14:40:02 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_color_rgb_int(t_color_table *table, char c)
{
	int	i;

	i = 0;
	while (table[i].c != c )
		i++;
	return (table[i].rgb);
}

static void	malloc_xpm_rgb(t_cardinal *xpm)
{
	int	i;

	xpm->rgb = malloc(sizeof(int *) * (xpm->height + 1));
	xpm->rgb[xpm->height] = NULL;
	i = 0;
	while (i < xpm->height)
	{
		xpm->rgb[i] = malloc(sizeof(int) * xpm->width);
		i++;
	}
}

/**
 * fill an int ** replacing the char of the xpm by the corresponding rgb int value
*/
void	fill_xpm_rgb(t_cardinal *xpm, t_color_table *table)
{
	int		i;
	int		j;
	char	*line;

	malloc_xpm_rgb(xpm);
	i = 0;
	while (i < xpm->height)
	{
		j = 0;
		line = get_next_line(xpm->fd);
		while (j < xpm->width)
		{
			xpm->rgb[i][j] = find_color_rgb_int(table, line[j + 1]);
			j++;
		}
		free(line);
		i++;
	}
}
