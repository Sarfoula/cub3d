/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:45:33 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/06 16:27:42 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*xpm_to_rgb(t_cardinal *xpm)
{
	t_color_table	*color_table;

	xpm->fd = open(xpm->cardinal_str, O_RDONLY);
	if (xpm->fd == -1)
		return (perror(ERR_OPEN), NULL);
	color_table = get_color_table(xpm);
	if (color_table == NULL)
		return (NULL);
	fill_xpm_rgb(xpm, color_table);
	// A EFFACER
	int	i = 0;
	while (i < xpm->nb_of_colors)
	{
		print_color_table(color_table[i]);
		i++;
	}
	//print_xpm_rgb(xpm);
	// A EFFACER
	free_color_table(color_table, xpm);
	return (NULL);
}

// int main()
// {
// 	t_cardinal xpm;

// 	xpm.cardinal_str = "eagle.xpm";
// 	xpm_to_rgb(&xpm);
// 	print_xpm_infos(xpm);

// 	//
// 	char *line;
// 	line = get_next_line(xpm.fd);
// 	while (line)
// 	{
// 		free(line);
// 		line = get_next_line(xpm.fd);
// 	}
// 	free_rgb(xpm.rgb);
// 	return (0);
// }