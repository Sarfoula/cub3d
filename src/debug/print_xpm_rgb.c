/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xpm_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:50:12 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/06 14:52:46 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_xpm_rgb(t_cardinal *xpm)
{
	int	i;
	int	j;

	i = 0;
	while (i < xpm->height)
	{
		j = 0;
		printf("--- line = %d ---\n", i);
		while (j < xpm->width)
		{
			printf("rgb = %d\n", xpm->rgb[i][j]);
			j++;
		}
		i++;
	}
}
