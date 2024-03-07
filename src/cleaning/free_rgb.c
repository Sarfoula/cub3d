/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarde-c <tbarde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:27:45 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/06 16:28:11 by tbarde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_rgb(int **rgb)
{
	int	i;
	while (rgb[i])
	{
		free(rgb[i]);
		i++;
	}
	free(rgb);
}

/**
 * Free the cardinal.rgb from textures
*/
void	free_xpm_rgb(t_textures *textures)
{
	free_rgb(textures->north.rgb);
	free_rgb(textures->south.rgb);
	free_rgb(textures->east.rgb);
	free_rgb(textures->west.rgb);
}
