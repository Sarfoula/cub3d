/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:27:45 by tbarde-c          #+#    #+#             */
/*   Updated: 2024/03/12 14:40:33 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_rgb(t_cardinal tex)
{
	int	i;

	for (i = 0; i < tex.width; i++)
		free(tex.rgb[i]);
	free(tex.rgb);
}

/**
 * Free the cardinal.rgb from textures
*/
void	free_xpm_rgb(t_textures *textures)
{
	free_rgb(textures->north);
	free_rgb(textures->south);
	free_rgb(textures->east);
	free_rgb(textures->west);
	get_next_line(-2);
}
