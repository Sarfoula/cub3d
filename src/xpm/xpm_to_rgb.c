/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:45:33 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/14 15:46:21 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*xpm_to_rgb(t_cardinal *xpm)
{
	t_color_table	*color_table;

	xpm->fd = open(xpm->cardinal_str, O_RDONLY);
	if (xpm->fd == -1)
	{
		ft_printf(2, "Error\n");
		return (perror(ERR_OPEN), NULL);
	}
	color_table = get_color_table(xpm);
	if (color_table == NULL)
		return (NULL);
	fill_xpm_rgb(xpm, color_table);
	free_color_table(color_table, xpm);
	close(xpm->fd);
	return (NULL);
}
