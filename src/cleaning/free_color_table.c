/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_color_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:27:15 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/06 16:27:23 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_color_table(t_color_table *table, t_cardinal *xpm)
{
	int	i;

	i = 0;
	while (i < xpm->nb_of_colors)
	{
		free(table[i].red_hex);
		free(table[i].green_hex);
		free(table[i].blue_hex);
		i++;
	}
	free(table);
}
